(1..1000).each do |i|
  File.open('data2', 'w') do |f|
    n = 1000#rand(1000) + 1
    q = 1000#rand(1000) + 1

    f.puts([n , q] * ' ')

    (1..q).each do |q_i|
      t = rand(3) + 1
      x = 0

      if t == 1
        x = rand(n) + 1
      elsif t == 2
        x = rand(n) + 1
      else
        x = rand(q_i) + 1
      end
      f.puts([t, x] * ' ')
    end
  end

  puts "Generated"
  test = `./clever < data2`
  correct = `./brute < data2`

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
