require "../../Tools/random.rb"

(1..1000).each do |i|
  File.open('data2', 'w') do |f|
    n = rand(5) + 1
    q = 1
    f.puts("#{n} #{q}")

    n.times do
      l = rand(10) + 1
      r = rand(10) + 1
      l,r=r,l if l > r
      f.puts("#{l} #{r}")
    end

    q.times do
      l = rand(10) + 1
      r = rand(10) + 1
      l,r=r,l if l > r
      f.puts("#{l} #{r}")
    end
  end

  puts "Generated"
  test = `./clever < data2`
  correct = `./correct < data2`

  if test.split('\n').map(&:to_i) == correct.split('\n').map(&:to_i)
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end

