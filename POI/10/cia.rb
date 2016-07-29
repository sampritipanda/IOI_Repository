def check(s)
    s = "." + s
    n = s.size - 1
    (1..n).each do |i|
        lim = (n + i + 1)/2
        ((i + 1)..lim).each do |j|
            x = i
            y = j
            equal = true
            while x < j do
                equal = false if s[x] != s[y]
                x += 1
                y += 1
            end
            return false if equal
        end
    end
    true
end

def construct(n)
    s = ""
    while s.size < n do
        c = ["a", "b", "c"].shuffle
        s += c[0]
        next if check(s)
        s.chop!
        s += c[1]
        next if check(s)
        s.chop!
        s += c[2]
        next if check(s)
        s = s[0..-4]
    end
    s
end
