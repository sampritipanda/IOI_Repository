(1..2500).each do |i|
  File.open('data2', 'w') do |f|
    n = rand(200000) + 1
    m = rand(100000) + 1

    f.puts("#{n} #{m}")

    m.times do
      l = rand(n) + 1
      r = rand(n) + 1
      l,r = r,l if l > r
      f.puts("#{l} #{r}")
    end
  end

  puts "Generated"
  correct = `time ./correct < data2`
  test = `time ./clever < data2`

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
