#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int C[101];
int P[101][101];
int N, M, K; 
long long dp[101][101][101];

// min amount to arrange (i..N) if previous tree is j color and k more groups have to be formed excluding current one
long long solve(int i, int j, int k) {
  if(k < 0) return LLONG_MAX/2;
  if(i == N + 1) {
    if(k == 0) return 0;
    else return LLONG_MAX/2;
  }
  if(dp[i][j][k] != -1) return dp[i][j][k];

  long long ans = LLONG_MAX/2;
  if(C[i] == 0) {
    for(int col = 1; col <= M; col++) {
      if(col == j) ans = min(ans, P[i][col] + solve(i + 1, col, k));
      else ans = min(ans, P[i][col] + solve(i + 1, col, k - 1));
    }
  }
  else {
    if(C[i] != j) ans = solve(i + 1, C[i], k - 1);
    else ans = solve(i + 1, C[i], k);
  }

  return dp[i][j][k] = ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> M >> K;

  for(int i = 1; i <= N; i++) cin >> C[i];
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> P[i][j];
    }
  }

  for(int i = 0; i <= 100; i++) {
    for(int j = 0; j <= 100; j++) {
      for(int k = 0; k <= 100; k++) {
        dp[i][j][k] = -1;
      }
    }
  }

  long long ans = solve(1, 0, K);
  if(ans == LLONG_MAX/2) ans = -1;
  cout << ans << endl;
}
