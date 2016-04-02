f,i,t=gets.strip.split.map(&:to_i)
a=f.times.map{gets.strip}
p i.times.count{|x|f.times.count{|y|a[y][x] == 'Y'}>=t}
# kitten
