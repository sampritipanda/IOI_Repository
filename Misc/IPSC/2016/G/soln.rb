dp = Array.new(1001) { Array.new(1001) {0} }
nxt = Array.new(1001) { Array.new(1001) {0} }

t = gets.to_i

t.times do
  s = gets.strip
  n = s.length

  (1..n).each do |l|
    (0...n).each do |i|
      j = i + l - 1
      begin
        dp[i][j] = eval(s[i..j])
      rescue SyntaxError => se
        dp[i][j] = -1
      end
      if l > 1
        dp[i][j] = [dp[i][j], [dp[i + 1][j], dp[i][j - 1]].max].max
      end
    end
  end

  puts dp[0][n - 1]
end
