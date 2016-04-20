print =: 1!:2&2
read =: 1!:1[3
in =. (read-.LF)-.CR

arr =. ". in
print #(#~ >:&(0 { arr))i.&.(p:inv) (1 + 1 { arr)

exit ''
