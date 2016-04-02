n = gets.to_i

a = Array.new(n) { Array.new(n) }

n.times.each { |i|
  x = gets.strip.split(' ')
  n.times.each { |j|
    a[i][j] = x[j].to_i
  }
}

n.times { |k|
  n.times { |i|
    n.times { |j|
      a[i][j] = [a[i][j], a[i][k] + a[k][j]].min
    }
  }
}

ans = 0
n.times { |i|
  n.times { |j|
    ans = [ans, a[i][j]].max
  }
}
puts ans
