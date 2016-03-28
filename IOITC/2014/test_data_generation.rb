(1..1).each do |i|
  File.open('data2', 'w') do |f|
    t = 5
    f.puts(t)

    t.times do
      n = 10000#rand(5) + 1
      q = 50000#rand(5) + 1
      f.puts(n)

      str = n.times.map { rand(1000) + 1 }.join(" ")
      f.puts(str)

      f.puts(q)

      q.times do
        type = 0#rand(2)

        if type == 1
          x = rand(n) + 1
          k = rand(1000) + 1
          f.puts("1 #{x} #{k}")
        else
          x = rand(n) + 1
          y = rand(n - x).to_i + x
          k = rand(y - x + 1) + 1
          f.puts("0 #{x} #{y} #{k}")
        end
      end
    end
  end
  puts "Generated"
  correct = `./correct < data2`
  test = `./clever < data2`

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
