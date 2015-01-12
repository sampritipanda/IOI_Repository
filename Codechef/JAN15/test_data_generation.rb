def generate(n, m)
  File.open('data2', 'w') do |file|
    file.write("#{n} #{m}")
    file.write("\n")
    n.times { file.write((rand*10).to_i.to_s) }
    file.write("\n")
    m.times do
      file.write("2 ")
      start = (rand*n).to_i + 1
      end_i = start + (rand*(n - start)).to_i
      file.write("#{start} #{end_i}\n")
    end
  end
end

generate(10**3, 10**3)
