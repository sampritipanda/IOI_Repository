# Generates Random Tree with N nodes (x(0|1)-based indexing)
def gen_random_tree(n, x=1)
  require 'set'

  edges = []

  tree = [0]
  not_tree = Array.new(n - 1) { |i| i + 1 }
  not_tree.shuffle!

  while edges.size != n - 1
    a = tree[rand(tree.size)]
    b = not_tree.pop

    edges << [a+x, b+x]
    tree << b
  end

  return edges
end


# Generates random connected graph with N nodes and M(>= N - 1 && <= N * (N - 1)/2) edges (x(0|1)-based indexing)
def gen_random_connected_graph(n, m, x=1)
  raise Exception, "Invalid number of edges #{n}, #{m}" if m < m - 1 or m > (n * (n - 1))/2

  edges = gen_random_tree(n, x)
  edge_set = Set.new edges

  (m - (n - 1)).times do
    u = 0; v = 0;
    loop do
      u = rand(n) + x
      v = rand(n) + x
      while u == v do
        v = rand(n) + x
      end
      break unless edges.include? [u, v] or edges.include? [v, u]
    end
    edges << [u, v]
    edge_set << [u, v]
  end

  return edges.shuffle
end
