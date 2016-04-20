load'regex'

print =: 1!:2&2
read =: 1!:1[3
in =. ('\r';' ') rxrplc (read-.LF)

print +/ ". in

exit ''
