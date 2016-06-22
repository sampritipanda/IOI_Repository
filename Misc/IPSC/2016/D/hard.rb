require './hard-data.rb'

color_map = {
  "#ff00ff" => "pink",
  "#ffff00" => "yellow",
  "#ff8800" => "orange",
  "#00ff00" => "green",
  "#0000ff" => "blue",
  "#ff0000" => "red",
}

sq = [[50, 50],
		 [50, 150],
		 [50, 250],
		 [150, 50],
		 [150, 150],
		 [150, 250]]

rect = [
	[250, 50],
	[250, 150],
	[250, 250],
	[450, 50],
	[450, 150],
	[450, 250]]

colors = "#ff0000 #00ff00 #0000ff #ffff00 #ff8800 #ff00ff".split(" ")

e = 47
d = 0

hm = {}

h = ->() do
  a = (0..5).to_a
  (1..5).each do |b|
    e *= 53
    e %= 1000000009
    k = e % (b + 1)
    a[b], a[k] = a[k], a[b]
  end
  a
end

l = ->() do
  f = h.()
  g = h.()

  6.times do |i|
    str = [color_map[colors[f[i]]], "square"]*' '
    hm[str] = [sq[i][0] + 5, sq[i][1] + 5]
  end

  6.times do |i|
    str = [color_map[colors[g[i]]], "wide rectangle"]*' '
    hm[str] = [rect[i][0] + 5, rect[i][1] + 5]
  end
end

time = (Time.now.to_f.round(3) - 10000)

move = ->(x, y) do
  puts "#{x} #{y} #{time}"
end

move_next = ->() do
  puts "next #{time}"
end

move_done = ->() do
  puts "done #{time}"
end


move.(203, 77)
l.()
e = 47

COMMANDS.each do |temp|
  move_next.()
  l.()
  c2 = temp.downcase.split(". ").flat_map { |x| x.split(" and ") }.map { |x| x.gsub(".", "") }
  c2.each do |c|
    if c.include? "background"
      move.(10, 10)
    elsif c.include? "seconds"
      t = c.scan(/ (\d+) seconds/)[0][0].to_i
      time += t
    elsif c.include? "times"
      res = c.scan(/click on the (.+) (\d+) times/)
      fig = res[0][0]
      cnt = res[0][1].to_i
      cnt.times do
        move.(*hm[fig])
      end
    else
      res = c.scan(/click on the (.+)$/)
      fig = res[0][0]
      move.(*hm[fig])
    end
  end
end

move_done.()
