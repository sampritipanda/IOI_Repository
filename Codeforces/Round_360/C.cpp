#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int C[501];
// i, sum_1, sum_2
bool dp[501][501][501];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, K; cin >> N >> K;
  for(int i = 1; i <= N; i++) cin >> C[i];

  dp[0][0][0] = true;
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j <= K; j++) {
      for(int k = 0; k <= K; k++) {
        dp[i][j][k] = dp[i - 1][j][k];
        if(C[i] <= j && dp[i - 1][j - C[i]][k]) dp[i][j][k] = true;
        if(C[i] <= k && dp[i - 1][j][k - C[i]]) dp[i][j][k] = true;
      }
    }
  }

  vector<int> ans;
  for(int i = 0; i <= K; i++) {
    if(dp[N][i][K - i]) ans.push_back(i);
  }

  cout << ans.size() << endl;
  for(int x: ans) cout << x << " "; cout << endl;
}
