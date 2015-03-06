`g++ correct_50_chefgrph.cpp -std=c++11 -g -o correct`
`g++ CHEFGRPH.cpp -std=c++11 -g -o chefgrph`

1000.times do |i|
  n = rand(110) + 1
  m = rand(110) + 1
  k = rand(30 + 1)
  nodes = []
  File.open('data2', 'w') do |f|
    f.puts("#{n} #{m} #{k}")
    k.times do
      e0 = rand(n + 1)
      e1 = rand(m)
      e1 = 0 if e0 == 0
      e2 = e0 + rand(n + 1 - e0) + 1
      e3 = rand(m)
      e3 = 0 if e2 == n + 1
      nodes << [e0, e1, e2, e3]
      f.puts("#{e0} #{e1} #{e2} #{e3}")
    end
  end

  expected = `./correct < data2`.strip.to_i
  actual = `./chefgrph < data2`.strip.to_i
  if expected != actual then
    puts "Testcase #{i}: Failure"
    puts "Expected: #{expected}"
    puts "Actual: #{actual}"
    puts "#{n} #{m} #{k}"
    p nodes
    break
  end
end
