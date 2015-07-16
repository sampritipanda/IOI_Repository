# Sereja and Game 2

import sys
from decimal import *
import operator
import functools

raw_input = sys.stdin.readline
getcontext().prec = 28

T = int(raw_input())

for i in xrange(T):
    N, M = map(int, raw_input().split())
    numer = Decimal(functools.reduce(operator.mul, map(Decimal, raw_input().split()), 1))
    denom = Decimal(numer)

    for i in xrange(1, N):
        denom += Decimal(functools.reduce(operator.mul, map(Decimal, raw_input().split()), 1))

    if denom == 0:
        denom = 1
    assert(False)
    print format(numer/denom, ".6f")
