#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int K;
vector<pair<int,int > > G[101];
int W[101];
int D[101][101];
int dp[101][51][101];

void dfs_calc(int src, int i, int d) {
  D[src][i] = d;

  for(auto it: G[i]) {
    dfs_calc(src, it.first, d + it.second);
  }
}

// i = current node, j = number of mills to be placed, k = nearest ancestor where mill was placed
int solve(int i, int j, int k) {
  if(dp[i][j][k] != -1) return dp[i][j][k];

  int tmp[K + 1], tmp2[K + 1];
  tmp[0] = W[i] * D[k][i];
  for(int a = 1; a <= K; a++) tmp[a] = INT_MAX/2;

  for(auto it: G[i]) {
    int u = it.first;
    for(int a = 0; a <= K; a++) {
      tmp2[a] = INT_MAX/2;
      for(int b = 0; b <= a; b++) {
        tmp2[a] = min(tmp2[a], tmp[a - b] + solve(u, b, k));
      }
    }
    for(int a = 0; a <= K; a++) tmp[a] = tmp2[a];
  }

  for(int a = 0; a <= K; a++) {
    dp[i][a][k] = tmp[a];
    if(a > 0 && i != k) dp[i][a][k] = min(dp[i][a][k], solve(i, a - 1, i));
  }
  return dp[i][j][k];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N >> K;

  for(int i = 1; i <= N; i++) {
    int p, d; cin >> W[i] >> p >> d;
    G[p].push_back({i, d});
  }

  for(int i = 0; i <= N; i++) {
    dfs_calc(i, i, 0);
  }

  memset(dp, -1, sizeof dp);
  cout << solve(0, K, 0) << endl;
}
