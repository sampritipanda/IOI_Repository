require "../../Tools/random.rb"

(1..1).each do |i|
  arr = []
  File.open('data2', 'w') do |f|
    n = 35000
    f.puts(n)

    a = (1..100000).to_a.shuffle[1..n]
    f.puts(a * ' ')

    edges = gen_random_tree(n)
    f.puts(edges.map { |x| x.join(' ')})

    m = 35000
    f.puts(m)
    m.times do
      t = rand(2) + 1
      if t == 1
        u = rand(n) + 1
        v = rand(n) + 1
        while u == v
          v = rand(n) + 1
        end

        f.puts("C #{u} #{v}")
      else
        u = rand(n) + 1
        v = rand(n) + 1
        while u == v
          v = rand(n) + 1
        end

        f.puts("F #{u} #{v}")
      end
    end
  end

  puts "Generated"
  test = `./clever < data2`

  if test != ""
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
