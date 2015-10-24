(1..1000).each do |i|
  File.open('data2', 'w') do |f|
    l = rand(10**3) + 1
    diff = rand(10**2)
    r = l + diff
    p = rand(10) + 1
    q = rand(10) + 1

    f.puts("#{l} #{r} #{p} #{q}")
  end

  puts "Generated"
  correct = `./brute < data2`
  test = `./fast < data2`

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
