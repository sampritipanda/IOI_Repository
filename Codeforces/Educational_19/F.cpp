#include <iostream>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

int N, M;
int X[5000];
pair<int, int> H[5000];
int P[5000], C[5000];
long long dp[2][5001];  // dp[i][j] = min cost using holes i..N and mouses j..M
long long cost_pref[5000];

inline long long cost(int L, int R) {
  if(L == 0) return cost_pref[R];
  return cost_pref[R] - cost_pref[L - 1];
}

void solve(int bit, int i, int L, int R, int start, int end) {
  if(L > R) return;

  int j = (L + R)/2;
  int opt = -1;

  dp[bit][j] = LLONG_MAX/2;
  for(int k = max(start, j - 1); k <= min(j + C[i] - 1, end); k++) {
    if(cost(j, k) + dp[bit ^ 1][k + 1] < dp[bit][j]) {
      dp[bit][j] = cost(j, k) + dp[bit ^ 1][k + 1];
      opt = k;
    }
  }

  solve(bit, i, L, j - 1, start, opt);
  solve(bit, i, j + 1, R, opt, end);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> X[i];
  sort(X, X + N);

  for(int i = 0; i < M; i++) {
    cin >> H[i].first >> H[i].second;
  }
  sort(H, H + M);
  for(int i = 0; i < M; i++) {
    P[i] = H[i].first;
    C[i] = H[i].second;
  }

  int bit = 0;

  for(int j = 0; j <= N; j++) dp[bit][j] = LLONG_MAX/2;
  dp[bit][N] = 0;

  for(int i = M - 1; i >= 0; i--) {
    bit ^= 1;
    dp[bit][N] = 0;
    long long pref = 0;
    for(int j = 0; j < N; j++) {
      pref += abs(X[j] - P[i]);
      cost_pref[j] = pref;
    }
    solve(bit, i, 0, N - 1, -1, N - 1);
  }

  long long ans = dp[bit][0];
  if(ans == LLONG_MAX/2) ans = -1;
  cout << ans << endl;
}
