n = gets.to_i

flip = ->(s) { s.each_char.map { |c| c == '+' ? '*' : '+'}.join }

if n == 0 then
  puts "+"
else
  ans = []
  ans[1] = ["++", "+*"]

  (2..n).each do |i|
    k = 2**i
    ans[i] = ans[i - 1].dup
    (k/2).times do |j|
      if j.even? then
        ans[i][j] += flip.(ans[i][j])
      else
        ans[i][j] += ans[i][j]
      end
    end
    (k/2).times do |j|
      ans[i] << ans[i - 1][j].reverse
    end
    ((k/2)...k).each do |j|
      if j.odd? then
        ans[i][j] = flip.(ans[i][j]) + ans[i][j]
      else 
        ans[i][j] = ans[i][j] + ans[i][j]
      end
    end
  end

  puts ans[n]
end
