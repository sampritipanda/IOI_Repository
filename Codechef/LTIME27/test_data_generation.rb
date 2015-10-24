(1..1000).each do |i|
  File.open('data2', 'w') do |f|
    t = rand(1000) + 1
    f.puts(t)
    t.times do
      n = rand(10) + 1
      str = n.times.map { ('a'..'c').to_a[rand(3)] }.join
      f.puts(str)
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
