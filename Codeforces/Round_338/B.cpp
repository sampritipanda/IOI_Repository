#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > G;
long long dp[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M; cin >> N >> M;

  G.resize(N + 1);

  while(M--) {
    int x, y; cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  long long ans = 0;

  for(int i = 1; i <= N; i++) {
    dp[i] = max(dp[i], 1LL);
    for(auto v: G[i]) {
      if(v > i) dp[v] = max(dp[v], dp[i] + 1);
    }

    ans = max(ans, dp[i] * int(G[i].size()));
  }

  cout << ans << endl;
}
