#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

vector<vector<pair<int, int> > > G;
vector<long long> D;
vector<bool> visited;
priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > Q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M, K; cin >> N >> M >> K;

  G.resize(N + 1);

  while(M--) {
    int u, v, x; cin >> u >> v >> x;
    G[u].push_back({-v, x});
    G[v].push_back({-u, x});
  }

  D.resize(N + 1);
  visited.resize(N + 1);

  fill(D.begin(), D.end(), LLONG_MAX/2);
  fill(visited.begin(), visited.end(), false);

  for(int i = 0; i < K; i++) {
    int s, y; cin >> s >> y;
    Q.push({y, s});
  }

  Q.push({0, -1});
  D[1] = 0;

  int ans = 0;

  while(Q.size() > 0) {
    auto curr = Q.top();
    Q.pop();
    int i = curr.second; long long dist = curr.first;

    if(i > 0) {
      if(visited[i]) {
        ans++;
        continue;
      }
    }

    if(i < 0) i = -i;

    if(visited[i]) continue;
    visited[i] = true;

    D[i] = min(D[i], dist);

    for(auto it: G[i]) {
      int v = it.first, len = it.second;
      if(v > 0 || (v < 0 && !visited[-v])) Q.push({D[i] + len, v});
    }
  }

  cout << ans << endl;
}
