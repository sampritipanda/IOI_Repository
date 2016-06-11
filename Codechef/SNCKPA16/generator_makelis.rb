(1..25451).to_a.reverse.each do |i|
  n = i#rand(100000) + 1
  File.open('data2', 'w') do |f|
    t = 1
    f.puts(t)

    t.times do
      f.puts("#{n}")
    end
  end

  puts "Generated"
  test = `./clever < data2`

  File.open('data2', 'w') do |f|
    f.puts(n)
    f.puts(test)
  end

  res = `./checker < data2`

  if res.to_i == 1
    puts "Testcase #{n}: Success"
  else
    puts "Testcase #{n}: Failure"
    break
  end
end

