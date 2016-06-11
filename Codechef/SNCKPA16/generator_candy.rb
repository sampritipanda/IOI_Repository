require "../../Tools/random.rb"

(1..1000).each do |i|
  a = rand(100) + 1
  b = rand(100) + 1
  c = rand(100) + 1
  d = rand(100) + 1

  File.open('data2', 'w') do |f|
    t = 1

    f.puts(t)

    t.times do
      f.puts("#{a} #{b} #{c} #{d}")
    end
  end

  ans = 934534905
  ans_pair = [-1, -1]
  (0..1000).each do |i|
    (0..1000).each do |j|
      curr = (a + c*i - b - d*j).abs
      if curr < ans
        ans = curr
        ans_pair = [i, j]
      end
    end
  end

  puts "Generated"
  test = `./clever < data2`

  if test.to_i == ans
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    puts "Expected: #{ans}, Got: #{test.chomp}"
    puts ans_pair*' '
    break
  end
end

