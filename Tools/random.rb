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
