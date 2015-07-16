(1..1).each do |i|
  File.open('data2', 'w') do |f|
    n = 1000#rand(5) + 1
    m = 1000#rand(5) + 1
    o = 1000000#rand(5) + 1
    f.puts("#{n} #{m} #{o}")

    n.times do
      str = m.times.map { rand(10**9 + 1) }.join(" ")
      f.puts(str)
    end

    j = 0
    while j < o do
      type = rand(2)
      x1 = rand(n) + 1
      x2 = rand(n) + 1
      y1 = rand(m) + 1
      y2 = rand(m) + 1
      k = rand(1000 + 1)
      v = rand(10**9 + 1)
      if(x1 <= x2 and y1 <= y2) then
        str = "#{type} #{x1} #{y1} #{x2} #{y2} #{k}"
        str += " #{v}" if type == 0
        f.puts(str)
        j += 1
      end
    end
  end
  puts "Generated"
  correct = `./correct < data2`
  test = `./clever < data2`

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
