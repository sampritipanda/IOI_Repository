(1..2500).each do |i|
  File.open('data2', 'w') do |f|
    n = rand(100 - 1) + 2

    arr = []
    n.times do
      x = rand(10000 + 1)
      y = x == 0 ? rand(10000) + 1 : rand(10000 + 1)
      arr << [x, y]
    end

    arr.uniq! { |x, y| Math.atan2(y, x) }

    f.puts(arr.size)
    arr.each do |x, y|
      f.puts("#{x} #{y}")
    end
  end
  puts "Generated"
  correct = `./correct < data2`.split(' ').sort
  test = `./hack < data2`.split(' ').sort

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
