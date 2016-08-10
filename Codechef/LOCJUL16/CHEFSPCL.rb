t = gets.to_i

t.times do
  a, b, k = gets.split.map &:to_i
  cnt = 0
  (a..b).each do |i|
    s = i.to_s
    n = s.size
    pos = true
    n.times do |x|
      (x...n).each do |y|
        if s[x..y].to_i % k == 0
          pos = false
          break
        end
      end
      break unless pos
    end
    cnt += 1 if pos
  end
  puts cnt
end
