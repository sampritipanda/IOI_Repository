#!/usr/bin/env python2

import sys

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

    def choice(self, seq):
        return seq[self.randint(0, len(seq) - 1)]

    def shuffle(self, data):
        data = data[:]
        n = len(data)
        for i in range(n):
            j = self.randint(i, n-1)
            data[i], data[j] = data[j], data[i]
        return data

class Checksum:
    def __init__(self): self.chk = 47

    def add(self, *xs):
        for x in xs:
            assert isinstance(x, (int, long))
            self.chk = (42 * self.chk + x) % 123455678901

    def check(self, expected, filename):
        if self.chk != expected:
            f = open(filename,'w')
            f.close() # truncate the output file to 0 bytes
            raise RuntimeError("Internal error, something went wrong. Expected checksum %d got %d" % (expected, self.chk) )

CHKSUM = 55447972574
FILENAME = 'f2.in'

random = PRNG(47*47)
chk = Checksum()

def randmerge(*qs):
    r = []
    qs = [list(reversed(q)) for q in qs]
    while qs:
        q = random.choice(qs)
        if not q:
            qs.remove(q)
            continue
        r.append(q.pop())
    return r

def make(N, C, RC=0, F=0, RS=0, RF=0, RP=0):
    q0 = []
    q1 = []
    q2 = []
    q3 = []
    qf = []

    for i in xrange(1, N//2): q1.append((0, i-1, i))
    for i in xrange(1, N//2): q2.append((0, N//2+i, N//2+i-1))
    for i in xrange(0, N//2): q3.append((1, i, N//2+i))
    for i in xrange(N, N+C):
        j = random.randint(0, N-1)
        if random.randint(0, 1):
            q0.append((0, i, j))
            q0.append((1, j, i))
        else:
            q0.append((0, j, i))
            q0.append((1, i, j))
    if RC:
        random.shuffle(q0)
    if F:
        for i in xrange(1, N):
            qf.append((1, random.randint(0, i-1), i))
        random.shuffle(qf)

    if RS:
        q = randmerge(q0, q1, q2, q3) + qf
    else:
        q = q0 + q1 + q2 + q3 + qf

    if RF:
        q.insert(random.randint(int(len(q)*0.75), len(q)), (0, 0, N//2))
    else:
        q.append((0, 0, N//2))

    permut = list(range(N + C))
    if RP:
        random.shuffle(permut)

    chk.add(N + C, len(q))
    print
    print N + C, len(q)
    for t, a, b in q:
        chk.add(t+1, permut[a]+1, permut[b]+1)
        print t+1, permut[a]+1, permut[b]+1

def rand(N, Q):
    chk.add(N, Q)
    print
    print N, Q
    for i in range(Q):
        a = random.randint(1, N)
        b = random.randint(1, N)
        while a == b: b = random.randint(1, N)
        t = random.randint(1, 2)
        chk.add(t, a, b)
        print t, a, b


def hard():
    print(28)

    make(4,  random.randint(0,5), RC=random.randint(0,1), F=random.randint(0,1), RS=random.randint(0,1), RP=1)
    make(10, random.randint(0,5), RC=random.randint(0,1), F=random.randint(0,1), RS=random.randint(0,1), RP=1)
    make(16, random.randint(0,5), RC=random.randint(0,1), F=random.randint(0,1), RS=random.randint(0,1), RP=1)
    make(20, random.randint(0,5), RC=random.randint(0,1), F=random.randint(0,1), RS=random.randint(0,1), RP=1)
    make(30, random.randint(0,5), RC=random.randint(0,1), F=random.randint(0,1), RS=random.randint(0,1), RP=1)
    rand(2,  1  )
    rand(2,  7  )
    rand(20, 1  )
    rand(20, 2  )
    rand(20, 20 )
    rand(22, 50 )
    rand(23, 150)
    rand(28, 250)
    rand(21, 500)

    make(10104, 613,        F=1, RS=1, RF=1, RP=1)
    make(4140,  1425, RC=1,            RF=1, RP=1)
    make(4846,  1326, RC=1,                  RP=1)
    make(3297,  627,             RS=1, RF=1,     )
    make(4060,  789,  RC=1, F=1, RS=1,       RP=1)
    make(6452,  1291,       F=1, RS=1,       RP=1)
    rand(5724, 7145)
    rand(46439, 167)

    make(31200,  100,    RC=1, F=1, RS=1, RF=1, RP=1)
    make(1000,   11000,  RC=1,      RS=1, RF=1, RP=1)
    make(50000,  50000,  RC=1, F=1, RS=1, RF=1, RP=1)
    make(300000, 100000, RC=1, F=1, RS=1, RF=1, RP=1)
    make(660000, 10,     RC=1,      RS=1, RF=1, RP=1)
    rand(1000000, 1000000)

if __name__ == '__main__':
    sys.stdout = f = open(FILENAME, 'w')
    hard()
    f.close()
    chk.check(CHKSUM, FILENAME)
