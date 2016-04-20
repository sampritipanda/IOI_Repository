#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cstring>

using namespace std;

vector<vector<pair<int, int> > > G;
vector<vector<int> > tree;
vector<pair<pair<int, int>, int> > edges;
vector<int> path, path_index;
map<pair<int, int>, bool> tree_edge, path_edge;
vector<int> D, D2, P;
set<pair<int, int> > PQ;
vector<int> ans;
const int MAX_LOG = 12;
int lca[7000][MAX_LOG + 1];
int depth[7000];
int N;

int dfs(int i, int p, int d) {
  depth[i] = d;

  for(auto v: tree[i]) {
    if(v == p) continue;

    dfs(v, i, d + 1);
  }
}

int lca_query(int a, int b) {
  if(depth[a] > depth[b]) swap(a, b);

  for(int j = MAX_LOG; j >= 0; j--) {
    if(lca[b][j] != -1 && depth[lca[b][j]] >= depth[a]) {
      b = lca[b][j];
    }
  }

  if(a == b) return a;

  for(int j = MAX_LOG; j >= 0; j--) {
    if(lca[a][j] != -1 && lca[b][j] != -1 && lca[a][j] != lca[b][j]) {
      a = lca[a][j];
      b = lca[b][j];
    }
  }

  return lca[a][0];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int M, Q; cin >> N >> M >> Q;

  G.resize(N); tree.resize(N); edges.resize(M); D.resize(N, INT_MAX/2); D2.resize(N, INT_MAX/2); P.resize(N, -1);

  for(int i = 0; i < M; i++) {
    int x, y, d; cin >> x >> y >> d;
    G[x].push_back({y, d}); G[y].push_back({x, d});

    edges[i] = {{x, y}, d};
  }

  D[0] = 0;
  PQ.insert({D[0], 0});
  while(!PQ.empty()) {
    auto it = *PQ.begin(); PQ.erase(it);
    int u = it.second, d = it.first;

    for(auto it: G[u]) {
      int v = it.first, cost = it.second;

      if(D[v] > D[u] + cost) {
        if(D[v] != INT_MAX/2) {
          PQ.erase({D[v], v});
        }
        D[v] = D[u] + cost;
        P[v] = u;
        PQ.insert({D[v], v});
      }
    }
  }

  if(D[N - 1] == INT_MAX/2) {
    while(M--) cout << -1 << endl;
    return 0;
  }

  D2[N - 1] = 0;
  PQ.clear();
  PQ.insert({D2[N - 1], N - 1});
  while(!PQ.empty()) {
    auto it = *PQ.begin(); PQ.erase(it);
    int u = it.second, d = it.first;

    for(auto it: G[u]) {
      int v = it.first, cost = it.second;

      if(D2[v] > D2[u] + cost) {
        if(D2[v] != INT_MAX/2) {
          PQ.erase({D2[v], v});
        }
        D2[v] = D2[u] + cost;
        PQ.insert({D2[v], v});
      }
    }
  }


  for(int i = 0; i < N; i++) {
    if(P[i] == -1) continue;

    tree[P[i]].push_back(i);
    tree[i].push_back(P[i]);

    tree_edge[{P[i], i}] = true;
    tree_edge[{i, P[i]}] = true;
  }

  memset(lca, -1, sizeof lca);

  for(int i = 0; i < N; i++) {
    lca[i][0] = P[i];
  }

  for(int j = 1; j <= MAX_LOG; j++) {
    for(int i = 0; i < N; i++) {
      if(lca[i][j - 1] != -1) {
        lca[i][j] = lca[lca[i][j - 1]][j - 1];
      }
    }
  }

  dfs(0, -1, 0);

  int node = N - 1;
  while(node != -1) {
    path.push_back(node);

    if(P[node] != -1) {
      path_edge[{P[node], node}] = true;
      path_edge[{node, P[node]}] = true;
    }
    node = P[node];
  }
  reverse(path.begin(), path.end());
  path_index.resize(N, -1);
  for(int i = 0; i < path.size(); i++) path_index[path[i]] = i;

  ans.resize(N, INT_MAX/2);
  for(auto edge: edges) {
    int u = edge.first.first, v = edge.first.second, d = edge.second;
    if(tree_edge[{u, v}]) continue;

    int l_u = lca_query(u, N - 1), l_v = lca_query(v, N - 1);
    if(l_u == -1 || l_v == -1) continue;

    int p_u = path_index[l_u], p_v = path_index[l_v];

    if(p_u > p_v) {
      swap(p_u, p_v);
      swap(u, v);
    }

    for(int i = p_u; i <= p_v - 1; i++) {
      ans[i] = min(ans[i], D[u] + d + D2[v]);
    }
  }

  for(int i = 0; i < N; i++) {
    if(ans[i] == INT_MAX/2) ans[i] = -1;
  }

  while(Q--) {
    int i; cin >> i;
    int u = edges[i].first.first, v = edges[i].first.second;

    if(path_edge[{u, v}]) {
      if(depth[u] > depth[v]) swap(u, v);
      cout << ans[path_index[u]] << endl;
    }
    else {
      cout << D[N - 1] << endl;
    }
  }
}

