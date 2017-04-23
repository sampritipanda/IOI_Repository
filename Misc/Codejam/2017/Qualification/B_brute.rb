t = gets.to_i

t.times do |testcase|
  n = gets.to_i
  ans = 0
  (1..n).to_a.reverse.each do |i|
    x = i.to_s.chars
    if x == x.sort
      ans = i
      break
    end
  end

  puts "Case ##{testcase + 1}: #{ans}"
end
