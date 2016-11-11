require "../../Tools/random.rb"

(1..100).each do |i|
  arr = []
  File.open('data2', 'w') do |f|
    n = rand(5) + 1
    f.puts("#{n}")

    a = n.times.map { rand(10) + 1 }
    f.puts(a.join ' ')

    tree = gen_random_tree(n)
    f.puts(tree.map { |x| x.join ' '})
  end

  puts "Generated"
  test = `./clever < data2`
  correct = `./wrong < data2`

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
