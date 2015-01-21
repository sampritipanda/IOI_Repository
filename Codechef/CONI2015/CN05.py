# False Fibonacci Series

import math

T = input()

while T:
    N = input()
    if N == 0:
        print 2
    elif N == 1:
        print 5
    else:
        N -= 1;
        ans = 3**N * 5 + (3**N-(-1)**N)/4
        ans = ans % 1000000007
        print ans

    T -= 1
