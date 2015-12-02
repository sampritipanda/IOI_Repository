n, b_x = gets.strip.split.map(&:to_i)

x = 0
a_x = gets.strip.split.map(&:to_i).reverse
a_x.each_with_index do |a, i|
  x += b_x**i * a
end

m, b_y = gets.strip.split.map(&:to_i)

y = 0
a_y = gets.strip.split.map(&:to_i).reverse
a_y.each_with_index do |a, i|
  y += b_y**i * a
end

if x == y then
  puts '='
elsif x < y then
  puts '<'
else
  puts '>'
end
