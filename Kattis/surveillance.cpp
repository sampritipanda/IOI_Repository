#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

const int MAX_N = 1000000;
const int MAX_LOG = 19;
vector<pair<int, int> > rev;
int F[MAX_N + 2];
int nxt[MAX_N + 2];
int dp[MAX_LOG][MAX_N + 2];

// Min number of nodes required to cover
int query(int L, int R) {
  if(L > R) return 0;

  int ans = 0;
  int i = L;
  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(dp[j][i] && dp[j][i] < R) {
      ans += (1 << j);
      i = dp[j][i] + 1;
    }
  }
  return ans + 1;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, K; cin >> N >> K;

  for(int i = 0; i < K; i++) {
    int L, R; cin >> L >> R;

    if(L > R) {
      rev.push_back({L, R});
      F[1]++; F[R + 1]--;
      nxt[1] = max(nxt[1], R);
      F[L]++; F[N + 1]--;
      nxt[L] = max(nxt[L], N);
    }
    else {
      F[L]++; F[R + 1]--;
      nxt[L] = max(nxt[L], R);
    }
  }

  bool pos = true;
  for(int i = 1; i <= N; i++) {
    F[i] += F[i - 1];
    if(F[i] == 0) pos = false;
  }
  if(!pos) {
    cout << "impossible" << endl;
    return 0;
  }

  for(int i = 1; i <= N; i++) {
    nxt[i] = max(nxt[i], nxt[i - 1]);
  }

  for(int i = 1; i <= N; i++) {
    dp[0][i] = nxt[i];
  }

  for(int j = 1; j < MAX_LOG; j++) {
    for(int i = 1; i <= N; i++) {
      if(dp[j - 1][i])
        dp[j][i] = dp[j - 1][dp[j - 1][i] + 1];
    }
  }

  int ans = INT_MAX/2;
  ans = min(ans, query(1, N));

  for(auto it: rev) {
    int L = it.first, R = it.second;
    ans = min(ans, 1 + query(R + 1, L - 1));
  }

  cout << ans << endl;
}
