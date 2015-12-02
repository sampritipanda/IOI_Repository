#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > G, G2;
vector<bool> visited, included, union_find;
vector<pair<int, int> > edges;
queue<pair<int, int> > Q;

int dfs(int i) {
  if(visited[i]) return 0;
  visited[i] = true;

  int ans = 0;
  if(included[i]) ans++;
  for(auto v: G[i]) {
    ans += dfs(v);
  }
  if(ans > 0) included[i] = true;
  return ans;
}

int dist(int u, int v) {
  while(!Q.empty()) Q.pop();
  fill(visited.begin(), visited.end(), false);

  Q.push({u, 0});

  while(!Q.empty()) {
    auto it = Q.front();
    Q.pop();
    int i = it.first, d = it.second;

    if(i == v) return d;
    if(visited[i]) continue;
    visited[i] = true;

    for(auto v: G2[i]) {
      Q.push({v, d + 1});
    }
  }
}

int bfs(int i) {
  while(!Q.empty()) Q.pop();
  fill(visited.begin(), visited.end(), false);

  Q.push({i, 0});
  int max_dist = 0, node = i;

  while(!Q.empty()) {
    auto it = Q.front();
    int i = it.first, d = it.second;
    Q.pop();

    if(visited[i]) continue;
    visited[i] = true;

    if(d > max_dist) node = i, max_dist = d;
    else if(d == max_dist && i < node) node = i;

    for(auto v: G2[i]) {
      Q.push({v, d + 1});
    }
  }

  return node;
}

int main() {
  int N, M; cin >> N >> M;
  G.resize(N + 1); G2.resize(N + 1); visited.resize(N + 1, false); included.resize(N + 1, false); union_find.resize(N + 1, false);

  for(int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);

    edges.push_back({u, v});
  }

  for(int i = 0; i < M; i++) {
    int c; cin >> c;
    included[c] = true;
  }

  int start = 1;
  for(int i = 1; i <= N; i++) {
    if(included[i]) {
      start = i;
      break;
    }
  }

  dfs(start);

  int edge_count = 0;
  for(auto it: edges) {
    int u = it.first, v = it.second;
    if(included[u] && included[v]) {
      edge_count++;

      G2[u].push_back(v);
      G2[v].push_back(u);
    }
  }

  int a = bfs(start);
  int b = bfs(a);

  cout << min(a, b) << endl;
  cout << 2 * edge_count - dist(min(a, b), max(a, b)) << endl;
}
