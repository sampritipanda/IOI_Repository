#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MOD 10007

long long A[100001], B[100001];
// dp[i][j] = number of ways for 1..i and j color painting required
long long dp[100001][21];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, C; cin >> N >> C;
  for(int i = 1; i <= N; i++) cin >> A[i];
  for(int i = 1; i <= N; i++) cin >> B[i];

  int Q; cin >> Q;

  while(Q--) {
    int P, a, b; cin >> P >> a >> b;
    A[P] = a;
    B[P] = b;

    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for(int i = 1; i <= N; i++) {
      dp[i][0] = (B[i] * dp[i - 1][0]) % MOD;
      for(int j = 1; j <= C; j++) {
        dp[i][j] = (A[i] * dp[i - 1][j - 1]) % MOD;
        dp[i][j] += (B[i] * dp[i - 1][j]) % MOD;
        dp[i][j] %= MOD;
      }
    }
    cout << dp[N][C] << endl;
  }
}

