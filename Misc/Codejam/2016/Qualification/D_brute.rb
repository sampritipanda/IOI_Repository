k, c = gets.strip.split.map(&:to_i)

freq = Array.new(k**c, 0)
freq_cnt = Hash.new(0)

(2**k).times do |mask|
  str = k.times.map { |i| (mask & (1 << i)).zero? ? 'G' : 'L' }.join

  str2 = str
  (c - 1).times do
    str2 = str2.chars.map { |c| c == 'L' ? str : 'G' * k }.join
  end
  str2.chars.each_with_index { |c, i| freq[i] += 1 if c == 'G' }
  # puts "#{str} => #{str2}"
end
# puts ' '*(k+4) + freq.map { |x| x.to_s }.join
freq.each do |x|
  freq_cnt[x] += 1
end

freq_cnt.each do |a, b|
  puts "#{a}    =   #{b}"
end
