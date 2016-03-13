(1..2500).each do |i|
  File.open('data2', 'w') do |f|
    n = 100000#rand(50) + 1
    f.puts(n)

    n.times do
      x = rand(2 * 10**9 + 1) - 10**9
      y = rand(2 * 10**9 + 1) - 10**9
      f.puts("#{x} #{y}")
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
