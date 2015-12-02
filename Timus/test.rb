def recursive(a, b)
  n = a.length
  if n == 0 or n == 1 then
    p b
    return
  end

  (1...n).each do |i|
    recursive(a - [a[0], a[i]], b + [[a[0], a[i]]])
  end
end

a = %w{Pablo Dan Andrew Tom Rob Jay}
recursive(a, [])
