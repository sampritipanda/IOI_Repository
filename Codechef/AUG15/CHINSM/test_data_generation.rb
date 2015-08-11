(1..1000).each do |i|
  File.open('data2', 'w') do |f|
    n = rand(5) + 1
    k = rand(5 + 1)
    f.puts("#{n} #{k}")

    str = n.times.map { rand(5) + 1}.join(" ")
    f.puts(str)
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
