# Division of Lands

require 'set'

n, m = gets.strip.split.map(&:to_i)
start = Time.now
graph = Array.new(n) { [] }
m.times do
  a, b, c = gets.strip.split.map(&:to_i)
  graph[a] << [b, c]
  graph[b] << [a, c]
end

nodes = (0...n).to_a
best_score = 99999999999999999999999999999999999
best_shuffle = nodes[0..(n/2 - 1)]

loop do
  elasped = Time.now - start
  if elasped >= 2.25 then
    puts best_shuffle.sort.join(' ')
    exit
  end

  partition = nodes.shuffle[0..(n/2 - 1)]

  node_set = Set.new partition
  curr_score = 0
  partition.each do |i|
    graph[i].each do |v|
      curr_score += node_set.include?(v[0]) ? 0 : v[1]
    end
  end

  if curr_score < best_score
    best_score = curr_score
    best_shuffle = partition
  end
end
