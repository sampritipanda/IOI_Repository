(1..1000).each do |i|
  arr = []
  File.open('data2', 'w') do |f|
    n = 1000
    f.puts(n)

    n.times do
      x = rand(2000 + 1) - 1000
      y = rand(2000 + 1) - 1000
      r = rand(5000) + 1
      f.puts("#{x} #{y} #{r}")
    end
  end

  puts "Generated"
  correct = `time ./brute < data2`
  test = `time ./clever < data2`

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
