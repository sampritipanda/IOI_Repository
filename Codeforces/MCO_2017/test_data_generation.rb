(1..300).each do |testcase|
  File.open('data2', 'w') do |f|
    f.puts("#{testcase} 3")
  end

  correct = `./correct < data2`
  clever = `./clever < data2`

  if correct == clever
    puts "Testcase #{testcase}: Success"
  else
    puts "Testcase #{testcase}: Failure"
    break
  end
end
