(1..25).each do |i|
  t = rand(100) + 1
  File.open('data2', 'w') do |f|
    f.puts(t)
    t.times do
      n = 3
      k = rand(99) + 2
      l = rand(k**n) + 1
      f.puts("#{n} #{k} #{l}")
    end
  end
  puts "Generated"
  correct = `python CHEFANUP_orig.py < data2`
  test = `python CHEFANUP.py < data2`

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
