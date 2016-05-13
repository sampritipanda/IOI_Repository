#include <iostream>
#include <algorithm>

#define MOD 1000000007

using namespace std;

long long dp[10001][41];

int main() {
  int Q; cin >> Q;

  while(Q--) {
    int N, M; cin >> N >> M;

    for(int j = 1; j <= M; j++) dp[1][j] = 1;

    for(int i = 2; i <= N; i++) {
      for(int j = 1; j <= M; j++) {
        dp[i][j] = 0;
        if(i % 2 == 1) {
          for(int k = 1; k < j; k++) {
            dp[i][j] += dp[i - 1][k];
            dp[i][j] %= MOD;
          }
        }
        else {
          for(int k = j + 1; k <= M; k++) {
            dp[i][j] += dp[i - 1][k];
            dp[i][j] %= MOD;
          }
        }
      }
    }

    long long ans = 0;
    for(int i = 1; i <= M; i++) ans = (ans + dp[N][i]) % MOD;
    cout << ans << endl;
  }
}
