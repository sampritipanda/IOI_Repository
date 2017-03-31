def check(f, g, h, n, m)
  (1..m).each do |x|
    return false unless g[h[x]] == x
  end
  (1..n).each do |x|
    return false unless h[g[x]] == f[x]
  end
  true
end

f = [0] + gets.split.map(&:to_i)
n = f.size - 1
m = gets.to_i

if m == 1
  functions_g = [[0]]
  n.times do
    functions_g[0] << 1
  end
else
  functions_g = (m**n).times.map do |hash|
    func = [0]
    n.times do |i|
      func << (hash.to_s(m).rjust(n, '0')[i].to_i(m) + 1)
    end
    func
  end
end

functions_h = (n**m).times.map do |hash|
  func = [0]
  m.times do |i|
    func << hash.to_s(n).rjust(m, '0')[i].to_i(n) + 1
  end
  func
end

functions_g.each do |g|
  functions_h.each do |h|
    if check(f, g, h, n, m)
      puts "SOLVE:"
      puts g.join(' ')
      puts h.join(' ')
    end
  end
end
