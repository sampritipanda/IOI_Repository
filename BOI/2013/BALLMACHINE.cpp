#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <cassert>

using namespace std;

#define MAX_LOG 17

// stores first occurence of 0 in range
int segtree[400001];
int leaf_id[100001];
vector<int> G[100001];
int min_node[100001];  // min node in subtree at i
int S[100001], R_S[100001];;
int lca[100001][17];
int timer = 0;

bool sort_compare(int L, int R) {
  return min_node[L] < min_node[R];
}

void dfs_min(int u) {
  min_node[u] = u;
  for(auto v: G[u]) {
    dfs_min(v);
    min_node[u] = min(min_node[u], min_node[v]);
  }
}

void dfs(int u) {
  for(auto v: G[u]) {
    dfs(v);
  }

  S[u] = ++timer;
  R_S[S[u]] = u;
}

void build_tree(int L, int R, int i) {
  segtree[i] = L;

  if(L == R) {
    leaf_id[L] = i;
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);
}

void update(int L, int R, int i, int x, int v) {
  if(L == R) {
    // remove ball
    if(v == 0) {
      segtree[i] = L;
    }
    // add ball
    else {
      segtree[i] = INT_MAX/2;
    }
    return;
  }

  int mid = (L + R)/2;
  if(x <= mid) {
    update(L, mid, 2*i + 1, x, v);
  }
  else {
    update(mid + 1, R, 2*i + 2, x, v);
  }

  segtree[i] = min(segtree[2*i + 1], segtree[2*i + 2]);
}

int main() {
  int N, Q; scanf("%d %d", &N, &Q);

  for(int i = 1; i <= N; i++) {
    for(int j = 0; j < MAX_LOG; j++) {
      lca[i][j] = -1;
    }
  }

  int root = -1;
  for(int i = 1; i <= N; i++) {
    int x; scanf("%d", &x);
    if(x == 0) root = i;
    else {
      G[x].push_back(i);
      lca[i][0] = x;
    }
  }

  for(int j = 1; j < MAX_LOG; j++) {
    for(int i = 1; i <= N; i++) {
      if(lca[i][j - 1] != -1)
        lca[i][j] = lca[lca[i][j - 1]][j - 1];
    }
  }

  dfs_min(root);

  for(int i = 1; i <= N; i++) {
    sort(G[i].begin(), G[i].end(), sort_compare);
  }

  dfs(root);

  build_tree(1, N, 0);

  while(Q--) {
    int t; scanf("%d", &t);

    if(t == 1) {
      int K; scanf("%d", &K);

      int last = -1;
      while(K--) {
        int add = segtree[0];
        last = R_S[add];
        update(1, N, 0, add, 1);
      }

      printf("%d\n", last);
    }
    else {
      int X; scanf("%d", &X);
      int cnt = 0;

      for(int j = MAX_LOG - 1; j >= 0; j--) {
        if(lca[X][j] != -1 && segtree[leaf_id[S[lca[X][j]]]] == INT_MAX/2) {
          cnt += (1 << j);
          X = lca[X][j];
        }
      }

      update(1, N, 0, S[X], 0);
      printf("%d\n", cnt);
    }
  }
}
