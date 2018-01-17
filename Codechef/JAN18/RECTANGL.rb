t = gets.to_i

t.times do
  a = gets.strip.split.map(&:to_i).sort
  if a[0] == a[1] && a[2] == a[3]
    puts "YES"
  else
    puts "NO"
  end
end
