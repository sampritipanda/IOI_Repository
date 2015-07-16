(1..1000).each do |i|
  File.open('data2', 'w') do |f|
    n = 10#rand(100000) + 1
    q = 10#rand(100000) + 1
    f.puts("#{n} #{q}")

    str = n.times.map { rand(10**9) + 1 }.join(" ")
    f.puts(str)

    q.times do
      type = [1, 2, 3, 4].shuffle.first
      l = rand(n) + 1
      r = rand(n - l).to_i + l
      if (1..3).include? type
        v = rand(10**9) + 1
        f.puts("#{type} #{l} #{r} #{v}")
      else
        f.puts("#{type} #{l} #{r}")
      end
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
