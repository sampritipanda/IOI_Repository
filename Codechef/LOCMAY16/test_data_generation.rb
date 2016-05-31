require "../../Tools/random.rb"

(1..1000).each do |i|
  arr = []
  File.open('data2', 'w') do |f|
    n = rand(3) + 2
    s = n.times.map { ['a', 'b', 'c'].shuffle.first }.join('')
    f.puts(s)

    k = rand(3) + 1
    m = rand(n - 1) + 1
    f.puts(k)
    f.puts(m)
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
