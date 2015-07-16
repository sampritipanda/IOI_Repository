T = input()
mod = (10** 9 + 7)

while T > 0:
    N, k = map(int, raw_input().split())
    denominator = (k - 1)**3
    numerator = k * (-2 * (3*N*N + 3*N + 2) * k**(N + 1) + (3*N**2 - 1) * k**(N+2) + 6 * (N + 1) * k**(2*N + 1) - 6*N*k**(2*N + 2) + k**(3*N + 2) + (3*N*N + 6*N + 2) * k**N - 2*k - 2)
    ans = numerator/denominator
    print ans % mod
    T -= 1
