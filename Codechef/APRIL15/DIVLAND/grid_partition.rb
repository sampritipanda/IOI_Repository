# https://github.com/dtak1114/grid_partition

require "set"
require "json"
require "csv"

module GridPartition
  def self.new
    GridPartition::Handler.new
  end

  class Graph < Set
    def initialize(enum=nil)
      #make it work like generic collection.
      #accept only Node-class instances.
      if enum.respond_to?(:select)
        garbage = enum.select{|e| !e.instance_of?(GridPartition::Node)}
        if garbage.any?
          raise ArgumentError,"#{garbage.first}:#{garbage.first.class.name} is not acceptable for Graph class!" 
        end
      end
      super(enum)
    end

    def dump
      return if self.any? {|e| e.nil?}
      nodes = self.map do |e|
        {
          :x => e.x,
          :y => e.y,
          :weight => e.weight
        }
      end
      return {
        :size => self.size,
        :weight => self.weight,
        :nodes => nodes
      }
    end

    def weight
      raise Error if self.empty?
      return self.reduce(0) {|sum,e| sum += e.weight}
    end

    def longer_side_length
      x_minmax = self.minmax {|a,b| a.x <=> b.x}
       x_length = x_minmax[1].x-x_minmax[0].x+1
      y_minmax = self.minmax {|a,b| a.y <=> b.y}
      y_length = y_minmax[1].y-y_minmax[0].y+1
      if x_length >= y_length
        return x_length
      else
        return y_length
      end
    end

    def x_longer?
      raise RuntimeError if self.empty?
       x_minmax = self.minmax {|a,b| a.x <=> b.x}
       x_length = x_minmax[1].x-x_minmax[0].x+1
      y_minmax = self.minmax {|a,b| a.y <=> b.y}
      y_length = y_minmax[1].y-y_minmax[0].y+1

      if x_length >= y_length
        return x_length
      else
        return false
      end
    end

    def each_column(&block)
       x_min,x_max = self.minmax {|a,b| a.x <=> b.x}
       (x_min.x..x_max.x-1).each do |x|
        sg1, sg2 = self.partition { |v| v.x <= x }
        yield Graph::new(sg1),Graph::new(sg2) if block_given?
      end
    end

    def each_row(&block)
      y_min,y_max = self.minmax {|a,b| a.y <=> b.y}
       (y_min.y..y_max.y-1).each do |y|
        sg1, sg2 = self.partition { |v| v.y <= y }
        yield Graph::new(sg1),Graph::new(sg2) if block_given?
      end
    end

  end  

  class Handler
    attr_accessor :result,:algorithm,:threshold
    def initialize
      @result = []
      @graph = GridPartition::Graph.new
      @algorithm = GridPartition::Algorithm::RecursivePartition
    end

    def set_graph(graph)
      @graph.merge(graph)
    end

    def clear_result
      @result.clear
    end

    def configure(&block)
      block.call(self) if block_given?
      #graph configure with block_given.
      #intended to use like this...
      # graph.configure do |g|
      #   g.nodes << node1 << node2
      #   g.partition_algorithm = GridPartition::Algorithm::RecursivePartition
      # end
    end

    def execute
      #delegate to => GridPartition::Algorithm
      # puts "handler#execute called"
      @algorithm.execute(@graph,@result) #if @algorithm.name(GridPartition::Algorithm)
      
      check_duplication()
    end  

    def result_dump(threshold)
      print "dumping data for threshold:#{threshold}..."
      begin
        open("#{threshold}","w") do |f|
          Marshal.dump(@result,f)
        end  
        print "done\n"
      rescue => e
        puts "#{e}"
        File.delete(threshold)
        abort
      end
    end

    def load_dump(threshold)
      print "loading dump for threshold:#{threshold}..."
      marshal_obj = nil
      open("#{threshold}","r") do |f|
        marshal_obj = Marshal.load(f)
      end  
      print "done\n"
      return marshal_obj
    end

    def check_dump_exist(threshold)
      if File.exists?(threshold)
        puts "dump file found for threshold:#{threshold}."
        return true
      else
        return false
      end
    end

    def check_duplication
      puts "result is empty" if @result.empty?

      result_merged_graph = GridPartition::Graph::new
      @result.each do |e|
        result_merged_graph.merge(e)
      end

      unless @graph.size == result_merged_graph.size
        puts "dupe found!! result.size:#{result_merged_graph.size} <-> graph.size#{@graph.size}"
      end
    end

  end

  class Node
    attr_reader :x,:y,:weight
    def initialize(x,y,weight)
      unless [x,y].all?{|e| e.is_a?(Integer) && e > 0} 
        raise ArgumentError 
      end
      @x,@y,@weight = x,y,weight.to_f
    end

    def eql?(other)
      #check identity for Set
      return self.hash == other.hash
    end

    def hash
      #secure up to (10^12) ~= 10^6 * 10^6
      #identical if coordination(x,y) are same.
      self.x*994997+self.y*999983;
    end
  end

  module Utility
    def csv_to_nodes(csv_filepath)
      data = CSV.table(csv_filepath)
      nodes = []

      data.each do |d|
        nodes << GridPartition::Node::new(d[:horizontal],d[:vertical],d[:value])
      end
      return nodes
    end

    module_function :csv_to_nodes
  end

  module Algorithm
    module RecursivePartition
      @@threshold = nil

      def threshold=(float)
        @@threshold = float  
      end

      def execute(graph,result)
        raise StandardError,"You need to specify threshold." if @@threshold.nil?
        # puts 'RecursivePartition::execute called'
        if not continuable?(graph)
          result << graph 
          return
        end

        best_index = Float::INFINITY
        #less index is better
        best_sg1, best_sg2 = nil,nil
        combination_found = false 

        if graph.x_longer?
          graph.each_column do |sg1,sg2|
            index = evaluate(sg1,sg2)
            if index <= @@threshold
              combination_found = true
              if index < best_index
                best_index = index 
                best_sg1,best_sg2 = sg1, sg2
              end
            end
          end
        else
          #row side
          graph.each_row do |sg1,sg2|
            index = evaluate(sg1,sg2)
            if index <= @@threshold
              combination_found = true
              if index < best_index
                best_index = index 
                best_sg1,best_sg2 = sg1, sg2
              end
            end
          end
        end

        if combination_found
          execute(best_sg1,result)
          execute(best_sg2,result)
        else
          result << graph
          return 
        end
      end

      def evaluate(g1,g2)
        raise Error if g1.none? or g2.none?
        #評価関数その3：D = | g1の重み/g1のノード数 -  g2の重み/g2のノード数|
        #20131011日のミーティングで決定
        return ((g1.weight / g1.size) - (g2.weight / g2.size)).abs
      end

      def continuable?(graph)
        # puts "RecursivePartition#continuable? called"

        return false unless graph.respond_to?(:empty?)
        return false if graph.empty?
        if graph.longer_side_length < 2  
          return false 
        else
          true
        end
      end

      module_function :execute,:continuable?,:evaluate,:threshold=
    end
  end
end

