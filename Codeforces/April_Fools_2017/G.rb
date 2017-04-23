s = gets.chomp
val = eval(s)
val.to_s.chars.each do |x|
  puts "+"*(x.ord)+".>"
end
