#!/usr/bin/python
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

### The main generator code starts here

TESTS = 20
MAXN = 5000
MAXM = 500000
CHKSUM = 83882146250
FILENAME = 'i2.in'

rng, chk = PRNG(47), Checksum()

def generate_testcase(f):
    n = rng.randint(MAXN // 2, MAXN)
    m = rng.randint(n, min(n*n // 5, MAXM))

    permutation = [1] + rng.permute(list(range(2, n))) + [n]
    
    f.write('\n{} {}\n'.format(n,m))
    chk.add(n)
    chk.add(m)
    
    for i in range(m):
        x = rng.randint(0, n-2)
        y = rng.randint(x+1, n-1)
        z = y - x
        dist = rng.randint(0, z * 100)
        hill = z * 100 - dist + rng.randint(0, 10)
        assert dist + hill > 0
        chk.add(permutation[x])
        chk.add(permutation[y])
        chk.add(dist)
        chk.add(hill)
        f.write('{} {} {} {}\n'.format(permutation[x], permutation[y], dist, hill))

if __name__ == "__main__":
    f = open(FILENAME,'w')
    f.write('{}\n'.format(TESTS))
    for i in range(TESTS): generate_testcase(f)
    f.close()
    chk.check(CHKSUM,FILENAME)

