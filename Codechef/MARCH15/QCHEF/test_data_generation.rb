(1..25).each do |i|
  File.open('data2', 'w') do |f|
    n = rand(10000) + 1
    m = rand(10000) + 1
    k = rand(10000) + 1
    f.puts("#{n} #{m} #{k}")

    str = n.times.map { rand(m) + 1}.join(" ")
    f.puts(str)

    k.times do
      l = rand(n) + 1
      r = rand(n - l).to_i + l
      f.puts("#{l} #{r}")
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
