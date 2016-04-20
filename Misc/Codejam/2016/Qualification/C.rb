require 'prime'

tests = gets.strip.to_i

(1..tests).each do |test_id|
  len, req = gets.strip.split.map(&:to_i)
  checks = Prime.first(25)
  ans = []

  while ans.size < req do
    str = '1' + (len - 2).times.map { rand() < 0.5 ? "1" : "0" }.join + '1'
    composite_for_all_base = true
    factors = []
    (2..10).each do |base|
      num = str.to_i(base)
      factor_found = false
      checks.each do |x|
        if num % x == 0
          factor_found = true
          factors << x
          break
        end
      end
      unless factor_found
        composite_for_all_base = false
        break
      end
    end
    if composite_for_all_base
      ans << [str, factors]
      ans.uniq! { |x| x[0] }
    end
  end

  puts "Case ##{test_id}:"
  puts ans.map { |x| x.flatten.join(' ') }
end
