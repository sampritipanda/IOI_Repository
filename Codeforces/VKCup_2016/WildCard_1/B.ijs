load'regex'   

print =: 1!:2&2
read =: 1!:1[3

in =. (read-.LF)-.CR
print ('December|January|February';'winter') rxrplc ('September|October|November';'autumn') rxrplc ('June|July|August';'summer') rxrplc ('March|April|May';'spring') rxrplc in

exit ''
