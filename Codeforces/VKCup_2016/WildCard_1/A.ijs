print =: 1!:2&2
read =: 1!:1[3

in =. (read-.LF)-.CR
print 1 + 2 ! 1 +/ ". in

exit ''
