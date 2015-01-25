# Just multiply

import re

def modpow(base, exp, modulus):
    base %= modulus
    result = 1
    while exp > 0:
        if exp & 1:
            result = (result * base) % modulus
        base = (base * base) % modulus
        exp >>= 1
    return result

T = input()
while T > 0:
    M, expr = raw_input().split()
    M = int(M)
    expr_arr = re.findall(r'\d+\*\*\d+', expr)
    result = 1
    for val in expr_arr:
        a, b = val.split("**")
        a, b = int(a), int(b)
        result = (result * modpow(a, b, M)) % M

    print result

    T -= 1
