#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> G[101];
long long dp[101][10001];
long long dp2[101][10001];
long long vis[101];
int M, K;

#define MOD 1000000007

void dfs(int i, int p, int j) {
  if(!vis[i]) {
    for(int u: G[i]) {
      if(u == p) continue;
      for(int k = 1; k <= M; k++) {
        dfs(u, i, k);
      }
      for(int k = 1; k <= M; k++) {
        dp2[u][k] = dp2[u][k - 1] + dp[u][k];
        dp2[u][k] %= MOD;
      }
    }
    vis[i] = true;
  }

  dp[i][j] = 1;
  for(int u: G[i]) {
    if(u == p) continue;

    long long curr = 0;
    if(j + K <= M) curr += dp2[u][M] - dp2[u][j + K - 1];
    if(j - K >= 0) curr += dp2[u][j - K];
    if(j - K == j + K) curr -= dp[u][j];
    while(curr < 0) curr += MOD;
    curr %= MOD;

    dp[i][j] = (dp[i][j] * curr) % MOD;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N >> M >> K;

    memset(dp, 0, sizeof dp);
    memset(dp2, 0, sizeof dp);
    memset(vis, false, sizeof vis);
    for(int i = 0; i <= N; i++) G[i].clear();

    for(int i = 0; i < N - 1; i++) {
      int u, v; cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }

    long long ans = 0;
    for(int i = 1; i <= M; i++) {
      dfs(1, 0, i);
      ans = (ans + dp[1][i]) % MOD;
    }
    cout << ans << endl;
  }
}
