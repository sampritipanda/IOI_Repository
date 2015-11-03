t, w, b = gets.strip.split.map(&:to_i)

l = w.lcm(b)
a = t/l * [w, b].min
a += [t % l + 1, [w, b].min].min
a -= 1

if w == b then
  puts "1/1"
else
  g = a.gcd(t)
  puts "#{a/g}/#{t/g}"
end
