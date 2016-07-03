(1..10).each do |testcase|
  File.open('data2', 'w') do |f|
    n = 300000
    m = 300000

    f.puts("#{n} #{m}")

    o = m.times.map { rand(n) + 1 }.join(' ')
    f.puts(o)

    p = n.times.map { rand(10**9) + 1 }.join(' ')
    f.puts(p)

    k = 300000
    f.puts(k)

    k.times do
      l = rand(m) + 1
      r = rand(m) + 1
      a = rand(10**9) + 1

      f.puts("#{l} #{r} #{a}")
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
