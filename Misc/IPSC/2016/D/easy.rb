require './easy-data.rb'

h = {
  "red square" => [82, 83],
  "yellow square" => [183, 74],
  "red wide rectangle" => [325, 70],
  "yellow wide rectangle" => [506, 76],
  "green square" => [79, 185],
  "orange square" => [177, 178],
  "green wide rectangle" => [290, 179],
  "orange wide rectangle" => [504, 173],
  "blue square" => [72, 272],
  "pink square" => [170, 271],
  "blue wide rectangle" => [286, 274],
  "pink wide rectangle" => [503, 272]
}

reg1 = /Click on the (.+) and then click on the (.+)\./
reg2 = /Click on the (.+)\./

puts "359 293"

COMMANDS.each do |c|
  puts "next"
  if c.scan(reg1) != []
    res = c.scan(reg1)
    puts h[res[0][0]]*' '
    puts h[res[0][1]]*' '
  else
    res = c.scan(reg2)
    puts h[res[0][0]]*' '
  end
end

puts "done"
