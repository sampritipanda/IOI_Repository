def slope(x1, y1, x2, y2)
  p = y2 - y1
  q = x2 - x1
  g = p.gcd(q)
  p /= g
  q /= g

  [p, q]
end

n = gets.chomp.to_i
points = n.times.map.with_index { |i| [gets.chomp.split.map(&:to_i), i + 1]}

points.sort! { |a, b| a[0] <=> b[0] }

ans = [points[0][1], points[1][1]]
const = slope(*points[0][0], *points[1][0])

(2...n).each do |i|
  if slope(*points[0][0], *points[i][0]) != const then
    ans << points[i][1]
    break
  end
end

puts ans.join(' ')
