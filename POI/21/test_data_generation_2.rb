require "../../Tools/random.rb"

(1..10000).each do |i|
  arr = []
  File.open('data2', 'w') do |f|
    n = rand(5) + 1
    s = rand(5) + 1
    f.puts("#{n} #{s}")

    t = n.times.map { rand(10 + 1) }.sort
    f.puts(t.join ' ')
  end

  puts "Generated"
  test = `./clever < data2`
  correct = `./correct < data2`

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
