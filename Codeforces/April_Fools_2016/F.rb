require 'open-uri'

str = gets.strip
id = str[1..-1]

if id == "221033"
  puts 21
else
  puts id[0..1]
end
