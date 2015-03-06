def gcd(a, b):
    if(b == 0):
        return a
    else:
        return gcd(b, a % b)

def rho(n, c):
    t = 2
    h = 2
    d = 1

    while d == 1:
        t = (t * t + c) % n
        h = (h * h + c) % n
        h = (h * h + c) % n
        d = gcd(t - h, n)

    if d == n:
        return rho(c, c + 1)
    else:
        return d

n = input()
while n > 1:
    fact = rho(n, 1)
    print fact
    n /= fact
