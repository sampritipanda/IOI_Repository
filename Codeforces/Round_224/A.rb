s = gets.strip
a, b = s.split("|")

a = a.to_s
b = b.to_s

c = gets.strip
c = c.to_s

if a.size > b.size then
  diff = a.size - b.size
  if diff <= c.size then
    b += c[0...diff]
    c = c[diff..-1]
  end
end
if a.size < b.size then
  diff = b.size - a.size
  if diff <= c.size then
    a += c[0...diff]
    c = c[diff..-1]
  end
end

if a.size == b.size
  if c.size.even?
    puts "#{a}#{c[0...c.size/2]}|#{b}#{c[c.size/2..-1]}"
  else
    puts "Impossible"
  end
else
  puts "Impossible"
end
