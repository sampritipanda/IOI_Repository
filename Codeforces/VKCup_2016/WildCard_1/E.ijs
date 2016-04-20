load'regex'



for_eg=: verb define
    print =: 1!:2&2
    read =: 1!:1[3
    in =. (read-.LF)-.CR

    arr =. ". in
    n =. # arr
    ans =. 0
    a=. 0
    
    while. a < n do.
      x=. a { arr
      b=. 0
      
      ans2=. 1
      while. b < n do.
        y =. b { arr
        if. (x - y * <. (x % y)) > 0 do. ans2=.0 end.
        b =. b + 1
      end.
      if. ans2 = 1 do. ans=.1 end.
      a=. a + 1
    end. 
    ans
)

print for_eg ''
exit ''
