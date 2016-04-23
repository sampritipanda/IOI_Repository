require "../../Tools/random.rb"

(1..100).each do |i|
  File.open('data2', 'w') do |f|
    n = 1000
    f.puts(n)

    str = n.times.map { rand(15) + 1 }.join(' ')
    f.puts(str)
  end

  puts "Generated"
  correct = `./correct < data2`
  test = `./clever < data2`

  test = test.split("\n")[0].to_i
  correct = correct.split("\n")[0].to_i

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
