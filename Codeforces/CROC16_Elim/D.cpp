#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> G[100001];
vector<pair<int, int> > edges;
int indeg[100001];
vector<int> groups[100001];
queue<pair<int, int> > Q; // {vertex, distance}
bool visited[100001];
int nex[100001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    edges.push_back({u, v});
    indeg[v]++;
  }

  for(int i = 1; i <= N; i++) {
    if(indeg[i] == 0) {
      Q.push({i, 0});
    }
  }

  while(!Q.empty()) {
    int u = Q.front().first, d = Q.front().second; Q.pop();

    if(visited[u]) continue;
    visited[u] = true;

    groups[d].push_back(u);

    for(auto v: G[u]) {
      indeg[v]--;

      if(indeg[v] == 0) Q.push({v, d + 1});
    }
  }

  bool pos = true;
  for(int i = 0; i <= N; i++) {
    if(groups[i].size() > 1) pos = false;
  }

  if(pos) {
    for(int i = 0; i < N - 1; i++) {
      nex[groups[i][0]] = groups[i + 1][0];
    }
    nex[groups[N - 1][0]] = -1;

    int ans = -1;
    for(int i = 0; i < M; i++) {
      int u = edges[i].first, v = edges[i].second;

      if(nex[u] == 0) continue;
      if(nex[u] == v) {
        nex[u] = 0;
        ans = i;
      }
    }
    cout << ans + 1 << endl;
  }
  else {
    cout << -1 << endl;
  }
}
