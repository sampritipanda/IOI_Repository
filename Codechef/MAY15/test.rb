t = gets.to_i

t.times do
  n, k = gets.strip.split.map(&:to_i)
  puts n + k
end
