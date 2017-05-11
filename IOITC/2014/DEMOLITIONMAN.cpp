#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>

using namespace std;

int B, N, K, D;
int X[17][17], Y[17][17], Z[17][17];
vector<int> G[17];
int near[17][17]; // near[i][j] = bitmask of other bombs in building i which are at a distance <= D from bomb j
int dp[17][1 << 17]; // dp[i][mask] = can i place mask bombs in ith building
int dp2[17][1 << 17];  // dp2[i][mask] = max number of bombs that can be activated among the bombs in this mask
int invalid_floors[2000001];

void solve(int i, int p) {
  for(int u: G[i]) {
    if(u == p) continue;
    solve(u, i);
  }

  for(int j = 0; j < (1 << N); j++) {
    dp2[i][j] = INT_MIN/2;
    if(dp[i][j]) dp2[i][j] = __builtin_popcount(j);

    for(int k = 0; k < N; k++) {
      if(j & (1 << k)) invalid_floors[Z[i][k] + 1000000] = 1;
    }
    for(int u: G[i]) {
      if(u == p) continue;
      int valid_mask = 0;
      for(int k = 0; k < N; k++) {
        if(invalid_floors[Z[u][k] + 1000000] == 0) valid_mask |= (1 << k);
      }
      dp2[i][j] += max(0, dp2[u][valid_mask]);
    }
    for(int k = 0; k < N; k++) {
      if(j & (1 << k)) invalid_floors[Z[i][k] + 1000000] = 0;
    }

    for(int k = 0; k < N; k++) {
      if(j & (1 << k)) dp2[i][j] = max(dp2[i][j], dp2[i][j & ~(1 << k)]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> B;
  cin >> N >> K >> D;

  for(int i = 0; i < B; i++) {
    for(int j = 0; j < N; j++) {
      cin >> X[i][j] >> Y[i][j] >> Z[i][j];
    }
  }

  for(int i = 0; i < B - 1; i++) {
    int u, v; cin >> u >> v; u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  for(int i = 0; i < B; i++) {
    for(int j = 0; j < N; j++) {
      near[i][j] = 0;
      for(int k = 0; k < N; k++) {
        if(k == j) continue;
        if(abs(X[i][k] - X[i][j]) + abs(Y[i][k] - Y[i][j]) + abs(Z[i][k] - Z[i][j]) <= D) {
          near[i][j] |= (1 << k);
        }
      }
    }
  }

  for(int i = 0; i < B; i++) {
    dp[i][0] = 1;
    for(int j = 1; j < (1 << N); j++) {
      dp[i][j] = 0;
      for(int k = 0; k < N; k++) {
        if(!(j & (1 << k))) continue;
        if(__builtin_popcount(near[i][k] & j) <= K) dp[i][j] |= dp[i][j & ~(1 << k)];
      }
    }
  }

  solve(0, -1);
  cout << dp2[0][(1 << N) - 1] << endl;
}
