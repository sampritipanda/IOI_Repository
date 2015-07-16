# Chef Anup

import math

T = input()

while T > 0:
    N, K, L = map(long, raw_input().split())
    ans = [0]*(N+1)
    for i in range(1, N + 1):
        if(pow(K, i - 1) > L): ans[N - i + 1] = 1 % K
        else: ans[N - i + 1] = long(math.ceil(L/float(pow(K, i - 1)))) % K
        if(ans[N - i + 1] == 0): ans[N - i + 1] = K

    print(" ".join(map(str, ans))[2:])

    T -= 1
