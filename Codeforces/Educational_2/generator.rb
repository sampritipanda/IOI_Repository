puts(10**5)
str = (1..10**5).to_a.join(' ')
puts(str)
(1..(10**5 - 1)).each do |i|
  puts("#{i} #{i + 1}")
end
