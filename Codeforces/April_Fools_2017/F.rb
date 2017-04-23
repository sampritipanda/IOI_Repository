a = gets.chomp.split.map(&:to_i)[1..-1]
x = []
100000.times do
  x << 5000
end
18000000.times do
    x.pop
    x << 10000
end
puts a.sort.join(' ')

