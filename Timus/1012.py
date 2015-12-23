n = input()
k = input()

dp = [[0 for x in range(2)] for x in range(n + 1)]

dp[0][1] = 1
dp[1][0] = 1
dp[1][1] = k - 1

for i in range(2, n + 1):
    dp[i][0] = dp[i - 1][1]
    dp[i][1] = (k - 1) * (dp[i - 1][0] + dp[i - 1][1])

print dp[n][1]
