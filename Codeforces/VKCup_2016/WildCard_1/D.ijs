load'regex'



for_eg=: verb define
    print =: 1!:2&2
    read =: 1!:1[3
    in =. (read-.LF)-.CR

    arr =. ". in
    ans =. 0
    n =. 1 - # arr
    
    i=. 0
    for. i.n do.
      diff=. | (((1 + i) { arr) - (i { arr))
      if. diff > ans do. ans=. diff end.
      i=. i + 1
    end. 
    ans
)

print for_eg ''
exit ''
