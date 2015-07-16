class PRNG:
    def __init__(self, seed): self.seed = seed

    def _random(self):
        M, A = 2147483647, 16807
        Q, R = M // A, M % A
        self.seed = A * (self.seed % Q) - R * (self.seed // Q)
        if self.seed <= 0: self.seed += M
        return self.seed

    def randint(self, start, end):
        res = start + int(self._random() % (end - start + 1))
        assert start <= res <= end, "%d %d %d" % (start, res, end)
        return res

    def permute(self, data):
        data = data[:]
        n = len(data)
        for i in range(n):
            j = self.randint(i, n-1)
            data[i], data[j] = data[j], data[i]
        return data

class Checksum:
    def __init__(self): self.chk = 47

    def add(self, x):
        assert isinstance(x, (int, long))
        self.chk = (42 * self.chk + x) % 123455678901

    def check(self, expected, filename):
        if self.chk != expected:
            f = open(filename,'w')
            f.close() # truncate the output file to 0 bytes
            raise RuntimeError("Internal error, something went wrong. Expected checksum %d got %d" % (expected, self.chk) )

TESTS1, TESTS2 = 6, 6
MINN, MAXN = 50000, 150000
CHKSUM = 111165565536
FILENAME = 's2.in'

import Queue

rng, chk = PRNG(47), Checksum()

f = open(FILENAME,'w')

f.write( str(TESTS1+TESTS2) + '\n' )
for i in range (TESTS1):
    f.write('\n')
    n=rng.randint(MINN, MAXN)
    if i==0: n=MAXN
    chk.add(n)
    f.write( str(n) + '\n' )
    cards = []
    for j in range (n):
        for suit in 'SDHC':
            cards.append(suit+str(j+1))
    cards=rng.permute(cards)
    for x in cards:
        chk.add(ord(x[0]))
        chk.add(int(x[1]))
    f.write(' '.join(cards) + '\n')

for i in range (TESTS2):
    f.write('\n')
    n=rng.randint(MINN, MAXN)
    if i==0: n=MAXN
    chk.add(n)
    cards = []
    for i,suit in enumerate('SDHC'):
        for j in range (n):
            cards.append(suit+str(j+1))
        for j in range (n):
            dist = rng.randint(0, min(5, n-j-1))
            cards[j+i*n], cards[j+i*n+dist] = cards[j+i*n+dist], cards[j+i*n]
    newcards = []
    qs = []
    for i in range(4):
        qs.append( Queue.Queue() )
        for j in range (n):
            qs[i].put( cards[i*n+j] )
    j=0
    while j!=4*n:
        q=rng.randint(0, 3)
        if not(qs[q].empty()):
            newcards.append(qs[q].get())
            j+=1
    f.write( str(n) + '\n' )
    for x in newcards:
        chk.add(ord(x[0]))
        chk.add(int(x[1]))
    f.write(' '.join(newcards) + '\n')
f.close()
chk.check(CHKSUM,FILENAME)
