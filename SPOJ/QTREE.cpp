#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_LOG 14

vector<vector<pair<int, int> > > G;
vector<pair<int, int> > edges;

bool leaf[10000];
int size[10000];
int heavy_child[10000];
int parent[10000];
int cost[10000];   // cost of edge from i to parent[i]
int visited[10000];
int chain_head[10000];
int path_index[10000];
int lca[10000][MAX_LOG];
int level[10000];
vector<int> chains;
vector<int> chain[10000];
vector<int> segtree[10000];

void reset() {
  G.clear();
  edges.clear();
  chains.clear();

  for(int i = 0; i < 10000; i++) {
    leaf[i] = false;
    size[i] = 0;
    heavy_child[i] = -1;
    parent[i] = -1;
    cost[i] = 0;
    visited[i] = false;
    chain_head[i] = -1;
    path_index[i] = -1;
    level[i] = -1;
    chain[i].clear();
    segtree[i].clear();
    for(int j = 0; j < MAX_LOG; j++) {
      lca[i][j] = -1;
    }
  }
}

void dfs(int i, int l) {
  int degree = 0;

  level[i] = l;
  size[i] = 1;
  for(vector<pair<int, int> >::iterator it = G[i].begin(); it != G[i].end(); it++) {
    int u = it->first; if(u == parent[i]) continue;

    parent[u] = i;
    cost[u] = it->second;
    degree++;
    dfs(u, l + 1);
    size[i] += size[u];
  }

  int max_size = 0, max_node = -1;
  for(vector<pair<int, int> >::iterator it = G[i].begin(); it != G[i].end(); it++) {
    int u = it->first; if(u == parent[i]) continue;

    if(size[u] > max_size) {
      max_size = size[u];
      max_node = u;
    }
  }
  heavy_child[i] = max_node;

  if(degree == 0) leaf[i] = true;
}

void build_tree(int L, int R, int i, int chain_id) {
  if(L == R) {
    segtree[chain_id][i] = cost[chain[chain_id][L]];
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1, chain_id);
  build_tree(mid + 1, R, 2*i + 2, chain_id);
  segtree[chain_id][i] = max(segtree[chain_id][2*i + 1], segtree[chain_id][2*i + 2]);
}

int query(int L, int R, int i, int qL, int qR, int chain_id) {
  if(qL > qR) return 0;
  if(L > qR || R < qL) return 0;

  if(qL <= L && R <= qR) return segtree[chain_id][i];

  int mid = (L + R)/2;
  return max(query(L, mid, 2*i + 1, qL, qR, chain_id), query(mid + 1, R, 2*i + 2, qL, qR, chain_id));
}

void update(int L, int R, int i, int ind, int val, int chain_id) {
  if(L == R) {
    segtree[chain_id][i] = val;
    return;
  }

  int mid = (L + R)/2;
  if(ind <= mid) {
    update(L, mid, 2*i + 1, ind, val, chain_id);
  }
  else {
    update(mid + 1, R, 2*i + 2, ind, val, chain_id);
  }
  segtree[chain_id][i] = max(segtree[chain_id][2*i + 1], segtree[chain_id][2*i + 2]);
}

int lca_query(int u, int v) {
  if(level[u] > level[v]) swap(u, v);

  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(lca[v][j] != -1 && level[lca[v][j]] >= level[u])
      v = lca[v][j];
  }

  if(u == v) return u;

  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(lca[u][j] != -1 && lca[v][j] != -1 && lca[u][j] != lca[v][j])
      u = lca[u][j], v = lca[v][j];
  }

  return lca[u][0];
}

// assert(level[u] >= level[v])
int hld_query(int u, int v) {
  int ans = 0;
  while(chain_head[u] != chain_head[v]) {
    int chain_id = chain_head[u];
    ans = max(ans, query(0, chain[chain_id].size() - 1, 0, 0, path_index[u], chain_id));
    u = parent[chain_head[u]];
  }

  int chain_id = chain_head[u];
  ans = max(ans, query(0, chain[chain_id].size() - 1, 0, path_index[v] + 1, path_index[u], chain_id));
  return ans;
}

int main() {
  int T; scanf("%d", &T);

  while(T--) {
    reset();

    int N; scanf("%d", &N);
    G.resize(N);

    for(int i = 0; i < N - 1; i++) {
      int a, b, c; scanf("%d %d %d", &a, &b, &c); a--; b--;
      G[a].push_back(make_pair(b, c));
      G[b].push_back(make_pair(a, c));

      edges.push_back(make_pair(a, b));
    }

    dfs(0, 0);

    for(int i = 0; i < N; i++) {
      lca[i][0] = parent[i];
    }
    for(int j = 1; (1 << j) <= N; j++) {
      for(int i = 0; i < N; i++) {
        if(lca[i][j - 1] != -1) {
          lca[i][j] = lca[lca[i][j - 1]][j - 1];
        }
      }
    }

    vector<int> path;
    for(int i = 0; i < N; i++) {
      if(!leaf[i]) continue;

      path.clear();
      int l = i;
      while(l != -1 && !visited[l]) {
        path.push_back(l);
        visited[l] = true;
        if(parent[l] == -1 || heavy_child[parent[l]] != l) break;
        l = parent[l];
      }

      for(vector<int>::iterator it = path.begin(); it != path.end(); it++) {
        chain_head[*it] = path.back();
      }

      if(path.size() > 0) chains.push_back(path.back());

      int index = 0;
      for(vector<int>::reverse_iterator it = path.rbegin(); it != path.rend(); it++) {
        chain[chain_head[*it]].push_back(*it);
        path_index[*it] = index++;
      }
    }

    for(vector<int>::iterator it = chains.begin(); it != chains.end(); it++) {
      int i = *it;
      segtree[i].resize(chain[i].size() * 4);
      build_tree(0, chain[i].size() - 1, 0, i);
    }

    while(true) {
      char type[100]; scanf(" %s", type);

      if(type[0] == 'Q') {
        int u, v; scanf("%d %d", &u, &v); u--; v--;
        int l = lca_query(u, v);

        printf("%d\n", max(hld_query(u, l), hld_query(v, l)));
      }
      else if(type[0] == 'C') {
        int e, t; scanf("%d %d", &e, &t); e--;
        pair<int, int> edge = edges[e];

        int u = (parent[edge.first] == edge.second ? edge.first : edge.second);
        cost[u] = t;
        int chain_id = chain_head[u];
        update(0, chain[chain_id].size() - 1, 0, path_index[u], t, chain_id);
      }
      else break;
    }
  }
}
