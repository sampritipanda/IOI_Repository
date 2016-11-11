require "../../Tools/random.rb"

(1..1).each do |i|
  arr = []
  File.open('data2', 'w') do |f|
    t = 10

    f.puts(t)

    t.times do
      n = 100000
      f.puts(n)

      edges = gen_random_tree(n)
      f.puts(edges.map { |x| x.join(' ')})

      m = 100000
      f.puts(m)
      m.times do
        t = 2#rand(2) + 1
        if t == 1 
          u = rand(n) + 1
          v = rand(n) + 1
          f.puts("#{t} #{u} #{v}")
        else
          v = rand(n) + 1
          f.puts("#{t} #{v}")
        end
      end
    end
  end

  puts "Generated"
  test = `time ./clever < data2`

  if test != ""
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
