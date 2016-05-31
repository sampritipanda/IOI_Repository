#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[300];
int dp[300][300];

int solve(int i, int j) {
  if(i == j) return A[i];
  if(dp[i][j] != -1) return dp[i][j];

  dp[i][j] = 0;

  for(int k = i; k < j; k++) {
    if(solve(i, k) == solve(k + 1, j)) {
      dp[i][j] = max(dp[i][j], solve(i, k) + 1);
    }
  }

  return dp[i][j];
}

int main() {
  // freopen("248.in", "r", stdin);
  // freopen("248.out", "w", stdout);

  int N; cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      dp[i][j] = -1;
    }
  }

  solve(1, N);

  int ans = 0;
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      ans = max(ans, dp[i][j]);

  cout << ans << endl;
}
