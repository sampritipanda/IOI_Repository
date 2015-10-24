# gCube

from decimal import Decimal, getcontext

T = input()
getcontext().prec = 28

# http://rosettacode.org/wiki/Nth_root#Python
def find_root(n, A):
    n = Decimal(n)

    x_0 = A / n #step 1: make a while guess.
    x_1 = 1     #need it to exist before step 2
    while True:
        #step 2:
        x_0, x_1 = x_1, (1 / n)*((n - 1)*x_0 + (A / (x_0 ** (n - 1))))
        if x_0 == x_1:
            return x_1

for t in xrange(1, T + 1):
    N, M = map(int, raw_input().split())
    A = map(int, raw_input().split())

    print "Case #" + str(t) + ":"
    for _ in xrange(M):
        L, R = map(int, raw_input().split())
        ans = Decimal(1.0)
        dim = R - L + 1
        for i in xrange(L, R + 1):
            ans = ans * pow(Decimal(A[i]), Decimal(1.0/dim));
        print ("%.10f" % ans)
