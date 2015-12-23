n, k = map(int, raw_input().split())

dp = [0 for i in range(n + 2)]
s = [0 for i in range(n + 3)]

dp[n + 1] = 1
s[n + 1] = 1

for i in range(n, -1, -1):
    dp[i] = dp[i + 1]
    dp[i] += s[i + 2] - s[min(i + k + 1, n + 1) + 1]
    s[i] = s[i + 1] + dp[i]

print dp[0]
