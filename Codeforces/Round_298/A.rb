require 'set'

n = gets.strip.to_i

if n == 1 or n == 2 then
	puts 1
	puts 1
elsif n == 3 then
	puts 2
	puts "1 3"
elsif n == 4 then
	puts 4
	puts "3 1 4 2"
else
	s = Set.new((1..n).to_a)
	ans = []
	while s.size > 1 do
		a = s.min
		b = n - s.min
		b = N if (a - b).abs == 1
		if !ans.empty? && (ans[-1] - a) == 1 then
			ans << b
			ans << a
		else
			ans << a
			ans << b
		end
		s.delete(a)
		s.delete(b)
	end
	
	ans << s.min if (s.size > 0 && (ans[-1] - s.min) != 1)
end