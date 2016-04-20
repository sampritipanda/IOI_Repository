require "../../Tools/random.rb"

(1..1).each do |i|
  arr = []
  File.open('data2', 'w') do |f|
    n = 300000
    f.puts(n)

    edges = gen_random_tree(n)
    f.puts(edges.map { |x| x.join(' ')})

    m = 300000
    f.puts(m)
    m.times do
      t = rand(2) + 1
      if t == 1 
        v = rand(n) + 1
        x = rand(10**9 + 7)
        k = rand(10**9 + 7)
        f.puts("#{t} #{v} #{x} #{k}")
      else
        v = rand(n) + 1
        f.puts("#{t} #{v}")
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
