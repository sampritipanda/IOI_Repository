(1..25).each do |i|
  t = rand(1) + 1
  File.open('data2', 'w') do |f|
    f.puts(t)
    t.times do
      n = rand(1000) + 1
      q = rand(10000) + 1
      f.puts(n)

      str = n.times.map { rand(20000 + 1) - 10000 }.join(' ')
      f.puts(str)

      f.puts(n)

      q.times do
        x1 = rand(n) + 1
        y1 = rand(n - x1).to_i + x1
        x2 = rand(n - y1).to_i + y1
        y2 = rand(n - x2).to_i + x2
        f.puts("#{x1} #{y1} #{x2} #{y2}")
      end
    end
  end
  puts "Generated"
  correct = `./brute < data2`
  test = `./clever < data2`

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
