(1..25).each do |i|
  File.open('data2', 'w') do |f|
    n = 100000#rand(200000) + 1
    m = 10**8
    f.puts("#{n}")

    str = n.times.map { rand(10**9) + 1 }.join(" ")
    f.puts(str)

    x = rand(n - 1)
    y = rand(n - 1)
    f.puts("#{m} #{x} #{y}")
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
