#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long dp[1 << 5][1000][1001];
int C[5];
int P[1000];
int V[1000];

int N, M, K;

// mask = used container, j = item, k = price
long long solve(int mask, int j, int k) {
  if(mask == (1 << K) - 1) return 0;
  if(j == N) return 0;
  if(dp[mask][j][k] != -1) return dp[mask][j][k];

  dp[mask][j][k] = max(dp[mask][j][k], solve(mask, j + 1, k));
  for(int i = 0; i < K; i++) {
    if(mask & (1 << i)) continue;

    if(P[j] <= k && V[j] <= C[i]) {
      dp[mask][j][k] = max(dp[mask][j][k], V[j] + solve(mask | (1 << i), j + 1, k - P[j]));
    }
  }

  return dp[mask][j][k];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    cin >> N >> M >> K;

    for(int i = 0; i < K; i++) cin >> C[i];
    for(int i = 0; i < N; i++) cin >> P[i];
    for(int i = 0; i < N; i++) cin >> V[i];

    memset(dp, -1, sizeof dp);

    cout << solve(0, 0, M) << endl;
  }
}
