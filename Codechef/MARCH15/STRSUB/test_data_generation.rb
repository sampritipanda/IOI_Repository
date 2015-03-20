(1..25).each do |i|
  t = rand(1) + 1
  File.open('data2', 'w') do |f|
    f.puts(t)
    t.times do
      n = rand(100000) + 1
      k = rand(n) + 1
      q = rand(1) + 1
      f.puts("#{n} #{k} #{q}")

      str = n.times.map { rand < 0.5 ? "0" : "1" }.join
      f.puts(str)

      q.times do
        l = rand(n) + 1
        r = rand(n - l).to_i + l
        f.puts("#{l} #{r}")
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
