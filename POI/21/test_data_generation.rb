require "../../Tools/random.rb"

(1..100).each do |i|
  arr = []
  File.open('data2', 'w') do |f|
    n = rand(5) + 1
    f.puts("#{n}")

    a = n.times.map { [rand(n) + 1, rand(n) + 1].join(' ') }
    f.puts(a)

    m = rand(1) + 1
    f.puts("#{m}")

    m.times do
      l = rand(n) + 1
      r = rand(n) + 1
      l,r = r,l if l > r

      f.puts("#{l} #{r}")
    end
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
