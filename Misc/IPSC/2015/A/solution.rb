# A + B

t = gets.strip.to_i

t.times do
  gets

  n_str = gets.strip
  n_optimal = n_str.split('').sort.reverse.join
  puts n_optimal[0..-2].to_i + n_optimal[-1].to_i
end
