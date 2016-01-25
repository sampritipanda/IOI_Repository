#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long dp[300][300];

int main() {
  long long D; int P, C, F, S; cin >> D >> P >> C >> F >> S;

  for(int i = 0; i <= C; i++) {
    for(int j = 0; j <= C; j++) {
      dp[i][j] = LLONG_MAX/2;
    }
  }

  for(int i = 1; i <= C; i++) {
    dp[i][i] = 0;
  }

  for(int i = 0; i < P; i++) {
    int A, B; cin >> A >> B;
    dp[A][B] = min(dp[A][B], -D);
  }

  for(int i = 0; i < F; i++) {
    int J, K, T; cin >> J >> K >> T;
    dp[J][K] = min(dp[J][K], T - D);
  }

  for(int i = 1; i <= C; i++) {
    for(int j = 1; j <= C; j++) {
      for(int k = 1; k <= C; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  bool neg_cycle = false;
  for(int i = 1; i <= C; i++) {
    if(dp[S][i] != LLONG_MAX/2 && dp[i][i] < 0) {
      neg_cycle = true;
      break;
    }
  }

  if(neg_cycle) {
    cout << -1 << endl;
  }
  else {
    long long ans = 0;
    for(int i = 1; i <= C; i++) {
      ans = max(ans, -dp[S][i]);
    }
    cout << ans + D << endl;
  }
}

