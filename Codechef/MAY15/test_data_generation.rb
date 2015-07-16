(1..20).each do |i|
  File.open('data2', 'w') do |f|
    t = rand(100)
    f.puts(t)
    t.times do
      n = rand(10) + 1
      k = rand(n) + 1
      f.puts("#{n} #{k}")
      str = n.times.map { |i| rand < 0.5 ? 0 : 1 }.join('')
      f.puts(str)
    end
  end
  puts "Generated"
  correct = `./correct < data2`
  test = `./segtree < data2`

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
