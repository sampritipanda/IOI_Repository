def repeated(n)
  digits = n.to_s.split('')
  (digits.include? 0) || (digits.uniq.size != digits.size)
end

(410000..999999999).each do |n|
  puts n if n % 10000 == 0
  exit if (repeated `echo #{n} | ./a.out`.strip.to_i)
end
