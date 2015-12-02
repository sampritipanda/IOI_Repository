n, s = map(int, raw_input().split())

if s % 2 == 1:
    print(0)
    exit()

s /= 2

# dp[i][j] = count of numbers of length i having sum j
dp = [[0 for j in range(s + 1)] for i in range(n + 1)]

dp[0][0] = 1

for i in range(1, n + 1):
    for j in range(0, s + 1):
        for k in range(0, 10):
            if j - k >= 0:
                dp[i][j] += dp[i - 1][j - k]

print(dp[n][s] * dp[n][s])
