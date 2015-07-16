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

    def random(self):
        return self._random() * 1.0 / 2147483647

    def randrange(self, n):
        return self._random() % n

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

CHKSUM = 68902063221
FILENAME = 'g2.in'

random = PRNG(47)
chk = Checksum()


def make(N, NR, Q, probs, gsr):
    P = [-1]
    for v in range(N-NR):
        r = random.random()
        nc = sum(r > p for p in probs)
        for i in range(nc):
            if len(P) < N-NR:
                if len(P) <= v: raise ValueError("what")
                P.append(v)

    for v in range(N-NR, N):
        P.append(random.randrange(v))

    D = [0] * N

    for v in reversed(range(N)):
        if v: D[P[v]] = max(D[P[v]], D[v] + 1)

    queries = []
    for i in range(Q):
        is_set = (i % gsr == 0)
        if random.random() < 0.05: is_set = not is_set
        v = random.randrange(N)
        if is_set:
            l = random.randint(0, 47) if random.random() < 0.1 else random.randint(D[v] // 2, D[v] + 7)
            queries.append((v+1, l, random.randint(1, Q)))
        else:
            queries.append((v+1, 0, 0))

    return Q + random.randrange(100), [p+1 for p in P[1:]], queries

TC = []
TC.append(make(1000000 - random.randrange(10000), 90000, 1000000 - random.randrange(10000), [2.0/1000000, 1 - 6.0/1000000], 2))
TC.append(make(1000000 - random.randrange(10000), 90000, 1000000 - random.randrange(10000), [10.0/1000000, 1 - 60.0/1000000], 2))
TC.append(make(1000000 - random.randrange(10000), 7, 1000000 - random.randrange(10000), [0, 0, 0.99], 2))
TC.append(make(1000000 - random.randrange(10000), 90000, 1000000 - random.randrange(10000), [0], 4))
TC.append(make(1000000 - 47, 1000000 - 47*47, 1000000 - random.randrange(10000), [0, 0, 0, 0], 2))

sys.stdout = f = open(FILENAME, 'w')

chk.add(len(TC))
print(len(TC))
for tc in TC:
    C, parents, queries = tc
    N = len(parents) + 1
    Q = len(queries)
    assert N <= 1000000
    assert C <= 1000000
    assert Q <= 1000000
    print
    chk.add(N, C, Q)
    chk.add(*parents)
    print N, C, Q
    print ' '.join(map(str, parents))
    for a, l, c in queries:
        assert 1 <= a <= N
        assert 0 <= min(l, N) <= N
        assert 0 <= c <= C
        if c == 0: assert l == 0
        chk.add(a, min(l, N), c)
        print a, min(l, N), c

f.close()
chk.check(CHKSUM, FILENAME)
