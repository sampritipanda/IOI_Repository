h, m = gets.chomp.split(':').map(&:to_i)
a = gets.chomp.to_i

t = Time.new(2002, 10, 31, h, m, 0)
t2 = t + a * 60

puts "#{t2.hour.to_s.rjust(2, '0')}:#{t2.min.to_s.rjust(2, '0')}"
