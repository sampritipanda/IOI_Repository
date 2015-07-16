#include <bits/stdc++.h>

using namespace std;

vector<int> graph[100010];
int depth[100010];
int start[100010], start_map[100010];
int subtree_size[100010];

int dfs_time = 0;

int N;

struct node {
  int depth = 0, lazy = 0, cnt = 0;
};

node segtree[400100];

void dfs(int i, int parent, int dep) {
  start[i] = dfs_time;
  start_map[dfs_time] = i;
  dfs_time++;

  depth[i] = dep;
  subtree_size[i] = 1;

  for(auto v: graph[i]) {
    if(v == parent) continue;
    dfs(v, i, dep + 1);
    subtree_size[i] += subtree_size[v];
  }
}

node merge_node(node L, node R) {
  node new_node;
  int cmp_a = L.depth + L.lazy;
  int cmp_b = R.depth + R.lazy;
  if(cmp_a == cmp_b) {
    new_node.depth = cmp_a;
    new_node.lazy = 0;
    new_node.cnt = L.cnt + R.cnt;
  }
  else if(cmp_a > cmp_b) {
    new_node.depth = cmp_a;
    new_node.lazy = 0;
    new_node.cnt = L.cnt;
  }
  else {
    new_node.depth = cmp_b;
    new_node.lazy = 0;
    new_node.cnt = R.cnt;
  }

  return new_node;
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i].depth = depth[start_map[L]];
    segtree[i].lazy = 0;
    segtree[i].cnt = 0;

    return;
  }

  int mid = L + (R - L)/2;
  build_tree(L, mid, 2*i + 2);
  build_tree(mid + 1, R, 2*i + 2);

  segtree[i] = merge_node(segtree[2*i + 1], segtree[2*i + 2]);
}

node basic_node;

void propagate(int i) {
  int l = 2*i + 1, r = 2*i + 2;
  segtree[l].lazy += segtree[i].lazy;
  segtree[r].lazy += segtree[i].lazy;

  segtree[i].depth += segtree[i].lazy;
  segtree[i].lazy = 0;
}

void update(int seg_start, int seg_end, int L, int R, int i, int val) {
  if(L > R) return;
  if(L > seg_end || R < seg_start) return;

  if(L <= seg_start && seg_end <= R) {
    segtree[i].lazy += val;
  }

  if(segtree[i].lazy > 0) propagate(i);
  int mid = L + (R - L)/2;
  update(L, mid, L, R, 2*i + 2, val);
  update(mid + 1, , L, R, 2*i + 2, val);
  build_tree(mid + 1, R, 2*i + 2);

  segtree[i] = merge_node(segtree[2*i + 1], segtree[2*i + 2]);
}

node query(int seg_start, int seg_end, int L, int R, int i) {
  if(L > R) return basic_node;
  if(L > seg_end || R < seg_start) return basic_node;

  if(L <= seg_start && seg_end <= R) return segtree[i];

  if(segtree[i].lazy > 0) propagate(i);
  int mid = (seg_start + seg_end)/2;
  return merge_node(query(seg_start, mid, L, R, 2*i + 1), query(mid + 1, seg_end, L, R, 2*i + 2));
}

node answer[100010];

void solve(int i, int parent) {
  answer[i] = query(0, N - 1, 0, N - 1, 0);

  for(auto u: graph[i]) {
    if(u == parent) continue;

    update(0, N - 1, start[u], start[u] + subtree_size[u] - 1, -1)
    modify(0,n-1,0,pos[u],pos[u]+sz[u]-1,-1);
    modify(0,n-1,0,0,pos[u]-1,1);
    modify(0,n-1,0,pos[u]+sz[u],n-1,1);
    solve(u,v);
    modify(0,n-1,0,pos[u],pos[u]+sz[u]-1,1);
    modify(0,n-1,0,0,pos[u]-1,-1);
    modify(0,n-1,0,pos[u]+sz[u],n-1,-1);
  }
}


int main() {
  cin >> N;

  for(int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for(int i = 0; i <= N; i++) depth[i] = 0;
  dfs(0, -1, 1);
  build_tree(0, N - 1, 0);

  find_ans(0, -1);
}
