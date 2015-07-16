str = gets.strip
puts (str.match(/AB(.*)BA/) || str.match(/BA(.*)AB/)) ? "YES" : "NO"
