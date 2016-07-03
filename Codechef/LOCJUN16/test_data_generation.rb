(1..10000).each do |i|
  n = 0
  m = 0
  File.open('data2', 'w') do |f|
    f.puts(1)

    n = rand(1000) + 2
    m = [rand(((n * (n - 1))/2).to_i) + 1, 100000].min

    g = []
    m.to_i.times do |i|
      u = rand(n) + 1
      v = ((1..n).to_a - [u]).shuffle.first
      g << [u, v].sort
    end
    g.uniq!
    g.sort!
    m = g.size
    f.puts("#{n} #{m}")

    f.puts g.map { |x| x.join ' ' }
  end

  puts "Generated"
  test = `./a.out < data2`

  if test.split("\n").size == m + 1
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end

end
