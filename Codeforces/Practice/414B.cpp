// Mashmokh and ACM

#include <iostream>
#include <algorithm>
#include <cstring>

#define MOD 1000000007

using namespace std;

// dp[i][j] = Number ways to build a sequence of length i when the number at ith position is j
int dp[2001][2001];

int main() {
  memset(dp, 0, sizeof dp);

  int N, K; cin >> N >> K;

  for(int j = 1; j <= 2000; j++) {
    dp[1][j] = 1;
  }

  for(int i = 1; i <= K - 1; i++) {
    for(int j = 1; j <= N; j++) {
      for(int k = j; k <= N; k += j) {
        dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % MOD;
      }
    }
  }

  int ans = 0;
  for(int j = 1; j <= N; j++) ans = (ans + dp[K][j]) % MOD;
  cout << ans << endl;
}
