#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int> > G[81];
int dp[81][81][81][81];

int solve(int i, int j, int L, int R) {
  if(j == K) return 0;
  if(dp[i][j][L][R] != -1) return dp[i][j][L][R];

  int ans = INT_MAX/2;
  for(auto it: G[i]) {
    int u = it.first, c = it.second;
    if(u > i && u <= R) {
      ans = min(ans, c + solve(u, j + 1, i + 1, R));
    }
    else if(u < i && u >= L) {
      ans = min(ans, c + solve(u, j + 1, L, i - 1));
    }
  }
  return dp[i][j][L][R] = ans;
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
        for(int l = 0; l <= N; l++)
          dp[i][j][k][l] = -1;

  int ans = INT_MAX/2;
  for(int i = 1; i <= N; i++) {
    ans = min(ans, solve(i, 0, 1, N));
  }
  if(ans == INT_MAX/2) ans = -1;
  cout << ans << endl;
}
