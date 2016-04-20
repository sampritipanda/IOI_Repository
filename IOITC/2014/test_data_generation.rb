(1..1000).each do |i|
  arr = []
  File.open('data2', 'w') do |f|
    n = rand(500) + 1
    f.puts(n)

    arr = n.times.map { rand(2000000 + 1) - 1000000 }
    f.puts(arr.join(' '))
  end

  puts "Generated"
  # correct = `./correct < data2`
  test = `./clever < data2`

  next if test[0] == '0'

  ans = test.split("\n")[2..-1]

  ans.each do |str|
    a = str.split(' ').map(&:to_i)
    arr[a[0] - 1] += arr[a[1] - 1] * 2**a[2]
  end

  if arr.count(0) == arr.size - 1
    puts "Testcase #{i}: Success"
  else
    puts "Testcase #{i}: Failure"
    break
  end
end
