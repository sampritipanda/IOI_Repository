require "../../Tools/random.rb"

(1..10000).each do |i|
  arr = []
  File.open('data2', 'w') do |f|
    n = rand(10) + 1
    m = 5
    f.puts("#{n} #{m}")

    a = n.times.map { rand(5) + 1 }
    f.puts(a.join ' ')

    b = (1..m).to_a.join ' '
    f.puts(b)
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
