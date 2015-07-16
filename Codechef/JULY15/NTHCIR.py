# Rohith and Circles

from decimal import *
from math import *

getcontext().prec = 28

t = input()
n, p, m, b = map(int, raw_input().split())
r_1, r_2, r_3, r_4 = map(Decimal, raw_input().split())
k_1, k_2, k_3, k_4 = -1/r_1, 1/r_2, 1/r_3, 1/r_4
X = k_1 + k_2

total = Decimal('0')
for i in xrange(t):
    n = (p * n) % m + b
    val = (n - 3) * k_4 - (n - 4) * k_3 + X * (n - 4) * ((n - 4) + 1)
    total += 1/val

print format(total, '.6f')
