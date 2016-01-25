// Coding Contest Creation

#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int N;
int D[100000];
int dp[200000][111][5];

// i = current index, j = previous element, k = number of problems
int solve(int i, int j, int k) {
  if(j > 110) return INT_MAX/2;

  if(dp[i][j][k] != -1) return dp[i][j][k];

  if(k == 4) return dp[i][j][k] = solve(i, j, 0);

  if(i == N) {
    if(k == 0) return dp[i][i][k] = 0;
    else return dp[i][j][k] = 1 + solve(i, j + 1, k + 1);
  }

  int ans = INT_MAX/2;
  if(k == 0) {
    ans = min(ans, solve(i + 1, D[i], 1));
  }
  else {
    if(D[i] > j && D[i] - j <= 10) ans = min(ans, solve(i + 1, D[i], k + 1));
    for(int d = 1; d <= 10; d++) {
      ans = min(ans, 1 + solve(i, j + d, k + 1));
    }
  }

  return dp[i][j][k] = ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> D[i];

    memset(dp, -1, sizeof dp);

    cout << "Case #" << t << ": " << solve(0, 0, 0) << endl;
  }
}

