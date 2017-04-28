(1..1).each do |i|
  arr = []
  File.open('data2', 'w') do |f|
    n = 200000
    q = 50000

    f.puts("#{n} #{q}")

    q.times do
      l = 0
      r = 0
      while l == r
        l = rand(n) + 1
        r = rand(n) + 1
      end
      f.puts("#{l} #{r}")
    end
  end

  puts "Generated"
  test = `/usr/bin/time ./clever < data2`
  correct = `./correct < data2`

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
