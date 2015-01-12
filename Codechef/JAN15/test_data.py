#coding=utf8

import random
import math

def gen_buckets(f):
    t = random.randint(10, 20)
    print >> f, t
    nlimit = 500000
    mlimit = 50000
    limit = 100000
    for i in xrange(t):
        n = random.randint(1, nlimit)
        m = random.randint(1, mlimit)
        print >> f, n, m

        for i in xrange(n):
            val = random.randint(1, limit)
            print >> f, val ,
        print >> f
        for i in xrange(m):
            ty = random.randint(1, 2)
            a = random.randint(0, n - 1)
            b = random.randint(a, n - 1)
            #a = 0
            #b = n - 1
            c = random.randint(-limit, limit)
            print >> f, 'A' if ty == 1 else 'Q', a, b, c


f = open("bucket.in", "w")
gen_buckets(f)
