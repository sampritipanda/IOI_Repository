n = int(input())
 
dp = [[0, 0] for i in range(n + 1)];
 
# 0 = red,  1 = white
 
dp[n][0] = dp[n][1] = 1
 
for i in range(n - 1, 0, -1):
    dp[i][0] += dp[i + 1][1]
    dp[i][1] += dp[i + 1][0]
 
    if i < n - 1:
        dp[i][0] += dp[i + 2][1];
        dp[i][1] += dp[i + 2][0];
 
print(dp[1][0] + dp[1][1])
