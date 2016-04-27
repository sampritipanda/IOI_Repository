#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <climits>
#include <cassert>
#include <stack>

using namespace std;

#define MAX_N 400000
#define MAX_LOG 19

int W[MAX_N + 1]; // Cost of Vertex
vector<int> G[MAX_N + 1];
int dfs_num[MAX_N + 1], dfs_low[MAX_N + 1];
bool art_point[MAX_N + 1];
int timer = 0;
int rootChild = 0;

int art_comp[MAX_N + 1];   // 0 => normal bi comp,   x => ith component consist of the art. point x
set<int> bi_comp[MAX_N + 1];    // {} => articulation pnt, {a, b, ..} => ith component consists of bi_comp elements
int comp_id[MAX_N + 1];   // {art point => id of art comp,  normal vert => id of bi comp}
int timer2 = 0;
stack<pair<int, int> > S;

set<int> tree[MAX_N + 1];
int size[MAX_N + 1];
int heavy_child[MAX_N + 1];
bool leaf[MAX_N + 1];
int parent[MAX_N + 1];
int depth[MAX_N + 1];

bool visited[MAX_N + 1];
int chain_id[MAX_N + 1];
int path_index[MAX_N + 1];
vector<vector<int> > paths;
vector<vector<int> > segtree;

int lca[MAX_N + 1][MAX_LOG];
multiset<int> C[MAX_N + 1]; // Cost of Cities in Biconnected Component

void dfs_art(int u, int p) {
  dfs_num[u] = dfs_low[u] = ++timer;
  S.push({p, u});

  for(int v: G[u]) {
    if(p == v) continue;

    if(dfs_num[v] == 0) {
      if(u == 1) rootChild++;

      dfs_art(v, u);
      if(dfs_low[v] >= dfs_num[u]) {
        art_point[u] = true;

        ++timer2;
        while(true) {
          auto it = S.top(); S.pop();
          int x = it.second;
          bi_comp[timer2].insert(x);
          if(!art_point[x]) comp_id[x] = timer2;
          if(it == make_pair(u, v)) break;
        }
        bi_comp[timer2].insert(u);
      }
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    else {
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }

  if(u != 1 && art_point[u]) {
    ++timer2;
    art_comp[timer2] = u;
    comp_id[u] = timer2;
  }
}

void dfs_tree(int u, int p, int d) {
  size[u] = 1;
  depth[u] = d;
  leaf[u] = false;
  parent[u] = p;
  heavy_child[u] = -1;
  tree[u].erase(p);

  for(int v: tree[u]) {
    dfs_tree(v, u, d + 1);
    size[u] += size[v];

    if(heavy_child[u] == -1) heavy_child[u] = v;
    else if(size[v] > size[heavy_child[u]]) heavy_child[u] = v;
  }

  if(size[u] == 1) leaf[u] = true;
}

void build_tree(int id, int L, int R, int i) {
  if(L == R) {
    segtree[id][i] = *C[paths[id][L]].begin();
    return;
  }

  int mid = (L + R)/2;
  build_tree(id, L, mid, 2*i + 1);
  build_tree(id, mid + 1, R, 2*i + 2);

  segtree[id][i] = min(segtree[id][2*i + 1], segtree[id][2*i + 2]);
}

int query(int id, int L, int R, int i, int qL, int qR) {
  if(L > qR || R < qL) return INT_MAX/2;

  if(qL <= L && R <= qR) return segtree[id][i];

  int mid = (L + R)/2;

  return min(query(id, L, mid, 2*i + 1, qL, qR), query(id, mid + 1, R, 2*i + 2, qL, qR));
}

void update(int id, int L, int R, int i, int x) {
  if(L == R) {
    segtree[id][i] = *C[paths[id][L]].begin();
    return;
  }

  int mid = (L + R)/2;
  if(x <= mid) {
    update(id, L, mid, 2*i + 1, x);
  }
  else {
    update(id, mid + 1, R, 2*i + 2, x);
  }

  segtree[id][i] = min(segtree[id][2*i + 1], segtree[id][2*i + 2]);
}

int lca_query(int a, int b) {
  if(depth[a] > depth[b]) swap(a, b);

  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(lca[b][j] != -1 && depth[lca[b][j]] >= depth[a])
      b = lca[b][j];
  }

  if(a == b) return a;

  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(lca[a][j] != -1 && lca[b][j] != -1 && lca[a][j] != lca[b][j]) {
      a = lca[a][j]; b = lca[b][j];
    }
  }

  assert(lca[a][0] == lca[b][0]);
  return lca[a][0];
}

// go up from b to a and find minimum on path
int hld_query(int a, int b) {
  int ans = INT_MAX/2;
  while(chain_id[b] != chain_id[a]) {
    ans = min(ans, query(chain_id[b], 0, paths[chain_id[b]].size() - 1, 0, 0, path_index[b]));
    b = parent[paths[chain_id[b]][0]];
  }
  ans = min(ans, query(chain_id[a], 0, paths[chain_id[a]].size() - 1, 0, path_index[a], path_index[b]));
  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M, Q; cin >> N >> M >> Q;

  for(int i = 1; i <= N; i++) cin >> W[i];

  while(M--) {
    int a, b; cin >> a >> b;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  timer = timer2 = 0;
  dfs_art(1, -1);
  art_point[1] = (rootChild > 1);

  if(art_point[1]) {
    ++timer2;
    art_comp[timer2] = 1;
    comp_id[1] = timer2;
  }
  else {
    for(int i = 1; i <= timer2; i++) {
      if(bi_comp[i].count(1) > 0) {
        comp_id[1] = i;
        break;
      }
    }
  }

  int X = timer2; // Number of Biconnected Components

  for(int i = 1; i <= X; i++) {
    if(art_comp[i]) continue;
    for(auto j: bi_comp[i]) {
      if(art_point[j]) {
        tree[comp_id[j]].insert(i);
        tree[i].insert(comp_id[j]);
      }
    }
  }

  dfs_tree(1, -1, 0);

  for(int i = 1; i <= N; i++) {
    C[comp_id[i]].insert(W[i]);
  }
  for(int i = 1; i <= X; i++) {
    if(art_comp[i] && parent[i] != -1) {
      C[parent[i]].insert(W[art_comp[i]]);
    }
  }

  timer = 0;
  for(int i = 1; i <= X; i++) {
    if(visited[i]) continue;
    if(!leaf[i]) continue;

    paths.push_back({});
    segtree.push_back({});
    int x = i;
    while(true) {
      visited[x] = true;
      paths[timer].push_back(x);

      if(parent[x] == -1) break;
      if(heavy_child[parent[x]] != x) break;

      x = parent[x];
    }
    reverse(paths[timer].begin(), paths[timer].end());
    segtree[timer].resize(paths[timer].size() * 4, INT_MAX/2);

    for(int j = 0; j < paths[timer].size(); j++) {
      int u = paths[timer][j];
      chain_id[u] = timer;
      path_index[u] = j;
    }

    build_tree(timer, 0, paths[timer].size() - 1, 0);

    timer++;
  }

  for(int j = 0; j < MAX_LOG; j++) {
    for(int i = 1; i <= X; i++) {
      lca[i][j] = -1;
    }
  }

  for(int i = 1; i <= X; i++) {
    lca[i][0] = parent[i];
  }

  for(int j = 1; j < MAX_LOG; j++) {
    for(int i = 1; i <= X; i++) {
      if(lca[i][j - 1] != -1) {
        lca[i][j] = lca[lca[i][j - 1]][j - 1];
      }
    }
  }

  while(Q--) {
    char type; cin >> type;

    if(type == 'C') {
      int a, w; cin >> a >> w;

      int b_a = comp_id[a];
      int old_val = W[a];
      C[b_a].erase(C[b_a].find(old_val));
      W[a] = w;
      C[b_a].insert(W[a]);
      update(chain_id[b_a], 0, paths[chain_id[b_a]].size() - 1, 0, path_index[b_a]);

      if(art_point[a]) {
        int par_bicomp = parent[comp_id[a]];
        if(par_bicomp != -1) {
          C[par_bicomp].erase(C[par_bicomp].find(old_val));
          C[par_bicomp].insert(w);
          update(chain_id[par_bicomp], 0, paths[chain_id[par_bicomp]].size() - 1, 0, path_index[par_bicomp]);
        }
      }
    }
    else {
      int a, b; cin >> a >> b;

      if(a == b) {
        cout << W[a] << endl;
        continue;
      }

      a = comp_id[a], b = comp_id[b];
      int l = lca_query(a, b);

      int ans = min(hld_query(l, a), hld_query(l, b));
      if(parent[l] != -1 && art_comp[parent[l]]) {
        ans = min(ans, *C[parent[l]].begin());
      }
      cout << ans << endl;
    }
  }
}
