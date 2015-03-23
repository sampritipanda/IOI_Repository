(1..1000).each do |i|
  File.open('data2', 'w') do |f|
    n = rand(500) + 1
    k = rand(20) + 1
    q = rand(20) + 1
    f.puts("#{n} #{k}")

    str = n.times.map { (rand(10**2) + 1) * 10 }.join(" ")
    f.puts(str)

    f.puts(q.to_s)
    q.times do
      f.puts((rand(10**3) + 1)*10000000)
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
