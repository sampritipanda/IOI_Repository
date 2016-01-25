l, r, k = gets.chomp.split(' ').map(&:to_i)

ans = []

power = 1

while power <= r do
  if power >= l then
    ans << power
  end
  power *= k
end

if ans.size == 0 then
  puts -1
else
  puts ans.join(' ')
end
