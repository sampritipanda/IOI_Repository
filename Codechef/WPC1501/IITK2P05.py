# Factorization

import math

def factors(n):
    while n % 2 == 0:
        print 2,
        n /= 2

    limit = int(math.sqrt(n))
    for i in range(3, limit + 1, 2):
        while n % i == 0:
            print i,
            n /= i

    if n > 2:
        print n,

    print

t = input()
while t > 0:
    n, phi = raw_input().split()
    n, phi = int(n), int(phi)
    factors(n)

    t -= 1
