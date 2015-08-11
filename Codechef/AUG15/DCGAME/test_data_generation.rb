(1..1000).each do |i|
  File.open('data2', 'w') do |f|
    n = rand(5) + 1
    m = rand(5) + 1
    f.puts("#{n} #{m}")

    str = n.times.map { rand(5) + 1}.join(" ")
    f.puts(str)

    m.times do
      c = ['>', '<', '='].shuffle.first
      k = rand(5) + 1
      x = ['C', 'D'].shuffle.first
      f.puts("#{c} #{k} #{x}")
    end
  end

  puts "Generated"
  correct = `./correct < data2`
  test = `./fast < data2`

  if test == correct
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
