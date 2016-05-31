(1..2500).each do |i|
  File.open('data2', 'w') do |f|
    n = rand(50) + 1
    str1 = n.times.map { rand < 0.2 ? -1 : rand(10 + 1) }

    m = ((str1.count(-1))..15).to_a.shuffle.first

    f.puts("#{n} #{m}")
    str2 = m.times.map { rand(10 + 1) }

    f.puts(str1.join(' '))
    f.puts(str2.join(' '))
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
