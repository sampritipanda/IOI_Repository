(1..25).each do |i|

  t = rand(500) + 1
  File.open('data2', 'w') do |f|
    f.puts(t)
    t.times do
      l = rand(10000 - 1) + 1
      r = rand(10000 - l) + l
      f.puts("#{l} #{r}")
    end
  end
  correct = `./brute < data2`
  test = `./clever < data2`

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
