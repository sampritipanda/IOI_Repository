(1..10).each do |testcase|
  File.open('data2', 'w') do |f|
    n = 100000
    f.puts(n)

    a = n.times.map { rand(2*10000 + 1) - 10000 }.join(' ')
    f.puts(a)

    q = 100000
    f.puts(q)

    q.times do
      t = ''
      loop do
        t = ['Q'].shuffle[0]
        if t == 'D' && n == 1
          next
        else
          break
        end
      end

      if t == 'I'
        i = rand(n + 1) + 1
        x = rand(2*10000 + 1) - 10000
        n += 1
        f.puts("#{t} #{i} #{x}")
      elsif t == 'D'
        i = rand(n) + 1
        n -= 1
        f.puts("#{t} #{i}")
      elsif t == 'R'
        i = rand(n) + 1
        x = rand(2*10000 + 1) - 10000
        f.puts("#{t} #{i} #{x}")
      else
        l = rand(n) + 1
        r = rand(n) + 1
        l,r = r,l if l > r

        f.puts("#{t} #{l} #{r}")
      end
    end
  end

  puts "Generated"
  correct = `time ./correct < data2`
  test = `time ./clever < data2`

  if test == correct
    puts "Testcase #{testcase}: Success"
  else
    puts "Testcase #{testcase}: Failure"
    break
  end
end
