#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int> > G[81];
int dp[81][81][81][2]; // dp[i][j][k][l] = (i = current node, j = number of offices left, k = boundary, l = (0 = go left, 1 = go right)

int solve(int i, int j, int k, int l) {
  if(j == K) return 0;
  if(dp[i][j][k][l] != -1) return dp[i][j][k][l];

  int ans = INT_MAX/2;
  for(auto it: G[i]) {
    int u = it.first, c = it.second;
    if(l == 0 && u < i && u >= k) {
      ans = min(ans, c + solve(u, j + 1, k, 0));
      ans = min(ans, c + solve(u, j + 1, i - 1, 1));
    }
    else if(l == 1 && u > i && u <= k) {
      ans = min(ans, c + solve(u, j + 1, k, 1));
      ans = min(ans, c + solve(u, j + 1, i + 1, 0));
    }
  }
  return dp[i][j][k][l] = ans;
}

int main() {
  cin >> N >> K; K--;
  int M; cin >> M;
  while(M--) {
    int u, v, c; cin >> u >> v >> c;
    G[u].push_back({v, c});
  }

  for(int i = 0; i <= N; i++)
    for(int j = 0; j <= N; j++)
      for(int k = 0; k <= N; k++)
        for(int l = 0; l < 2; l++)
          dp[i][j][k][l] = -1;

  int ans = INT_MAX/2;
  for(int i = 1; i <= N; i++) {
    ans = min(ans, solve(i, 0, 1, 0));
    ans = min(ans, solve(i, 0, N, 1));
  }
  if(ans == INT_MAX/2) ans = -1;
  cout << ans << endl;
}
