#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, K, D;
int P[300001];
bool P_R[300001];
vector<int> G[300001];
vector<pair<int, int> > edges;
vector<int> ans;
int stat[300001];   // stat[i] = nearest station to i

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> K >> D;
  for(int i = 1; i <= K; i++) {
    cin >> P[i];
    P_R[P[i]] = true;
  }

  for(int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
    edges.push_back({u, v});
  }

  queue<vector<int> > Q;
  for(int i = 1; i <= N; i++) {
    if(P_R[i]) Q.push({i, 0, i});
  }

  while(!Q.empty()) {
    auto it = Q.front(); Q.pop();
    int u = it[0], d = it[1], src = it[2];
    if(stat[u]) continue;

    stat[u] = src;
    if(d == D) continue;

    for(int v: G[u]) {
      Q.push({v, d + 1, src});
    }
  }

  for(int i = 0; i < N - 1; i++) {
    int u = edges[i].first, v = edges[i].second;
    if(stat[u] != stat[v]) ans.push_back(i + 1);
  }

  cout << ans.size() << endl;
  for(int i: ans) cout << i << " "; cout << endl;
}
