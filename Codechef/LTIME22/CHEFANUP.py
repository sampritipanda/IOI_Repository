# Chef Anup

import math

T = input()

while T > 0:
    N, K, L = map(long, raw_input().split())
    result = []
    letters = list(range(1, K + 1))
    L -= 1
    while L > 0:
        curr = letters[L % len(letters)]
        result.append(curr)
        L = L / len(letters)

    while len(result) < N:
        result.append(1)

    result.reverse()
    print(" ".join(map(str, result)))

    T -= 1

