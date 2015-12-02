(1..2500).each do |i|
  File.open('data2', 'w') do |f|
    t = rand(40910) + 1
    f.puts(t)

    t.times do
      n = rand(30) + 1
      m = rand(30) + 1
      k = rand([n * m, 50].min) + 1

      f.puts("#{n} #{m} #{k}")
    end
  end

  puts "Generated"
  correct = `./correct < data2`
  test = `./hack < data2`

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
