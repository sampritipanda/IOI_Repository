#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > G;

bool leaf[100000];
int size[100000];
int heavy_child[100000];
int parent[100000];
int visited[100000];
int chain_head[100000];
int path_index[100000];
vector<int> chains;
vector<int> chain[100000];
vector<int> segtree[100000];

void reset() {
  G.clear();
  chains.clear();

  for(int i = 0; i < 100000; i++) {
    leaf[i] = false;
    size[i] = 0;
    heavy_child[i] = -1;
    parent[i] = -1;
    visited[i] = false;
    chain_head[i] = -1;
    path_index[i] = -1;
    chain[i].clear();
    segtree[i].clear();
  }
}

void dfs(int i) {
  int degree = 0;

  size[i] = 1;
  for(auto u: G[i]) {
    if(u == parent[i]) continue;

    parent[u] = i;
    degree++;
    dfs(u);
    size[i] += size[u];
  }

  int max_size = 0, max_node = -1;
  for(auto u: G[i]) {
    if(u == parent[i]) continue;

    if(size[u] > max_size) {
      max_size = size[u];
      max_node = u;
    }
  }
  heavy_child[i] = max_node;

  if(degree == 0) leaf[i] = true;
}

int merge(int L, int R, int l_value, int r_value) {
  int mid = (R - L)/2;

  if(l_value == -1) {
    if(r_value == -1) return -1;
    else {
      return (mid + 1) + r_value;
    }
  }
  else return l_value;
}

int query(int L, int R, int i, int qL, int qR, int chain_id) {
  if(qL > qR) return -1;
  if(L > qR || R < qL) return -1;

  if(qL <= L && R <= qR) return segtree[chain_id][i];

  int mid = (L + R)/2;
  return merge(L, R, query(L, mid, 2*i + 1, qL, qR, chain_id), query(mid + 1, R, 2*i + 2, qL, qR, chain_id));
}

void update(int L, int R, int i, int ind, int chain_id) {
  if(L == R) {
    if(segtree[chain_id][i] == -1) segtree[chain_id][i] = 0;
    else segtree[chain_id][i] = -1;

    return;
  }

  int mid = (L + R)/2;
  if(ind <= mid) {
    update(L, mid, 2*i + 1, ind, chain_id);
  }
  else {
    update(mid + 1, R, 2*i + 2, ind, chain_id);
  }
  segtree[chain_id][i] = merge(L, R, segtree[chain_id][2*i + 1], segtree[chain_id][2*i + 2]);
}

// Going up from u to 0
int hld_query(int u) {
  int ans = -1;
  while(u != -1) {
    int chain_id = chain_head[u];
    int new_ans = query(0, chain[chain_id].size() - 1, 0, 0, path_index[u], chain_id);
    if(new_ans != -1) ans = chain[chain_id][new_ans];
    u = parent[chain_head[u]];
  }
  if(ans != -1) ans++;
  return ans;
}

int main() {
  reset();

  int N, Q; scanf("%d %d", &N, &Q);
  G.resize(N);

  for(int i = 0; i < N - 1; i++) {
    int a, b; scanf("%d %d", &a, &b); a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(0);

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

    for(auto it: path) {
      chain_head[it] = path.back();
    }

    if(path.size() > 0) chains.push_back(path.back());

    int index = 0;
    for(auto it = path.rbegin(); it != path.rend(); it++) {
      chain[chain_head[*it]].push_back(*it);
      path_index[*it] = index++;
    }
  }

  for(auto i: chains) {
    segtree[i].resize(chain[i].size() * 4, -1);
  }

  while(Q--) {
    int type; scanf("%d", &type);

    if(type == 0) {
      int i; scanf("%d", &i); i--;
      int chain_id = chain_head[i];

      update(0, chain[chain_id].size() - 1, 0, path_index[i], chain_id);
    }
    else {
      int v; scanf("%d", &v); v--;
      printf("%d\n", hld_query(v));
    }
  }
}
