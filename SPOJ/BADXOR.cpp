#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

#define MOD 100000007

long long dp[1024][1001];

int main() {
  int test; cin >> test;

  for(int t = 1; t <= test; t++) {
    int N, M; cin >> N >> M;

    int A[N + 1], B[M + 1];
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i <= M; i++) cin >> B[i];

    for(int i = 0; i < 1024; i++)
      for(int j = 0; j <= 1000; j++)
        dp[i][j] = 0;

    dp[0][0] = 1;

    for(int j = 1; j <= N; j++) {
      for(int i = 0; i < 1024; i++) {
        dp[i][j] += dp[i ^ A[j]][j - 1];
        dp[i][j] %= MOD;
        dp[i][j] += dp[i][j - 1];
        dp[i][j] %= MOD;
      }
    }

    long long ans = 1;
    for(int i = 1; i <= N; i++) ans = (ans * 2) % MOD;

    for(int i = 1; i <= M; i++) {
      ans -= dp[B[i]][N];
      ans = (ans + MOD) % MOD;
    }

    cout << "Case " << t << ": " << ans << endl;
  }
}
