#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define MAX_LOG 17

vector<vector<pair<int, int> > > G;
vector<pair<int, pair<int, int> > > edges;
int level[100001], parent[100001], U[100001];
int cost[100001]; // cost[i] = cost of edge from parent[i] to i
int lca[100001][17];
int max_path[100001][17];

int find(int i) {
  if(U[i] == i) return i;
  else return U[i] = find(U[i]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);
  if(a != b) {
    U[a] = b;
  }
}

void dfs(int i, int l) {
  level[i] = l;

  for(auto it: G[i]) {
    int u = it.first, w = it.second;
    if(parent[i] == u) continue;

    parent[u] = i;
    cost[u] = w;

    dfs(u, l + 1);
  }
}

int lca_query(int a, int b) {
  if(level[a] > level[b]) swap(a, b);

  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(lca[b][j] != -1 && level[lca[b][j]] >= level[a])
      b = lca[b][j];
  }

  if(a == b) return a;

  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(lca[a][j] != -1 && lca[b][j] != -1 && lca[a][j] != lca[b][j])
      a = lca[a][j], b = lca[b][j];
  }

  return lca[a][0];
}

// go up from a to b
int traverse_up(int a, int b) {
  int ans = 0;
  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(lca[a][j] != -1 && level[lca[a][j]] >= level[b]) {
      ans = max(ans, max_path[a][j]);
      a = lca[a][j];
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;
  G.resize(N + 1);

  for(int i = 0; i <= N; i++) {
    U[i] = i;
    parent[i] = -1;
    level[i] = -1;
    for(int j = 0; j < MAX_LOG; j++) {
      lca[i][j] = -1;
      max_path[i][j] = 0;
    }
  }

  for(int i = 0; i < M; i++) {
    int u, v, w; cin >> u >> v >> w;
    edges.push_back({w, {u, v}});
    edges.push_back({w, {v, u}});
  }

  sort(edges.begin(), edges.end());

  for(auto it: edges) {
    int u = it.second.first, v = it.second.second;
    int w = it.first;

    if(find(u) != find(v)) {
      merge(u, v);
      G[u].push_back({v, w});
      G[v].push_back({u, w});
    }
  }

  cost[0] = 0;
  dfs(1, 0);

  for(int i = 1; i <= N; i++) {
    lca[i][0] = parent[i];
    max_path[i][0] = cost[i];
  }

  for(int j = 1; j < MAX_LOG; j++) {
    for(int i = 1; i <= N; i++) {
      if(lca[i][j - 1] != -1) {
        lca[i][j] = lca[lca[i][j - 1]][j - 1];
        max_path[i][j] = max(max_path[i][j - 1], max_path[lca[i][j - 1]][j - 1]);
      }
    }
  }

  int Q; cin >> Q;

  while(Q--) {
    int s, d; cin >> s >> d;
    int l = lca_query(s, d);

    int ans = max(traverse_up(s, l), traverse_up(d, l));
    cout << ans << endl;
  }
}
