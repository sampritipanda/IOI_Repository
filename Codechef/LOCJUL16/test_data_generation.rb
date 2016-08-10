(1..10000).each do |i|
  File.open('data2', 'w') do |f|
    f.puts(6)
    a = rand(100000) + 1
    b = rand(100000) + 1
    a, b = b, a if a > b

    (2..7).each do |k|
      f.puts([a, b, k] * ' ')
    end
  end

  puts "Generated"
  test = `./clever < data2`
  correct = `ruby CHEFSPCL.rb < data2`

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end

end
