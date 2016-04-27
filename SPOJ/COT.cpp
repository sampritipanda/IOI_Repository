#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

struct tree {
  int val;
  tree *left, *right;

  tree(int _val = 0, tree* _left = NULL, tree* _right = NULL) {
    val = _val;
    left = _left;
    right = _right;
  }

  void build(int L, int R) {
    if(L == R) return;

    int mid = (L + R)/2;
    left = new tree(); left->build(L, mid);
    right = new tree(); right->build(mid + 1, R);
  }

  tree* update(int L, int R, int k) {
    if(k > R || k < L) return this;

    int mid = (L + R)/2;
    tree* new_node = new tree(val + 1);

    if(L != R) {
      new_node->left = left->update(L, mid, k);
      new_node->right = right->update(mid + 1, R, k);
    }

    return new_node;
  }
};

// Num Elements <= K between (u, v)   =>   F_K(1, u) + F_K(1, v) - F_K(1, lca(u, v)) - F_K(1, par(lca(u, v)))
int query(int L, int R, tree* u, tree* v, tree* l, tree* p_l, int K) {
  if(L == R) return L;

  int mid = (L + R)/2;
  int cnt = u->left->val + v->left->val - l->left->val - p_l->left->val;

  if(K <= cnt) {
    return query(L, mid, u->left, v->left, l->left, p_l->left, K);
  }
  else {
    return query(mid + 1, R, u->right, v->right, l->right, p_l->right, K - cnt);
  }
}

inline int scan() {
  int x = 0;
  char c = getchar_unlocked();
  while(c < '0' || c > '9') {
    c = getchar_unlocked();
  }
  while(c >= '0' && c <= '9') {
    x = (x<<1)+(x<<3)+c-'0';
    c = getchar_unlocked();
  }
  return x;
}

const int MAX = 100000;
const int MAX_LOG = 17;

int N;
vector<int> G[MAX + 1];
int lca[MAX + 1][MAX_LOG];
map<int, int> compres;
int R_compres[MAX + 1];
int W[MAX + 1];
int D[MAX + 1];
tree* root[MAX + 1];

void dfs(int i, int p, int d) {
  lca[i][0] = p;
  D[i] = d;

  root[i] = root[p]->update(1, N, W[i]);

  for(vector<int>::iterator it = G[i].begin(); it != G[i].end(); it++) {
    int u = *it;
    if(u == p) continue;
    dfs(u, i, d + 1);
  }
}

int lca_query(int u, int v) {
  if(D[u] > D[v]) swap(u, v);

  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(D[v] - (1 << j) >= D[u])
      v = lca[v][j];
  }

  if(u == v) return u;

  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(lca[u][j] && lca[v][j] && lca[u][j] != lca[v][j]) {
      u = lca[u][j]; v = lca[v][j];
    }
  }

  assert(lca[u][0] == lca[v][0]);
  return lca[u][0];
}

int main() {
  N = scan(); int M = scan();

  for(int i = 1; i <= N; i++) {
    W[i] = scan();
    compres[W[i]];
  }
  int timer = 0;
  for(map<int, int>::iterator it = compres.begin(); it != compres.end(); it++) {
    compres[it->first] = ++timer;
    R_compres[timer] = it->first;
  }
  for(int i = 1; i <= N; i++) W[i] = compres[W[i]];

  for(int i = 0; i < N - 1; i++) {
    int u = scan(), v = scan();
    G[u].push_back(v);
    G[v].push_back(u);
  }

  root[0] = new tree(); root[0]->build(1, N);
  dfs(1, 0, 0);

  for(int j = 1; j < MAX_LOG; j++) {
    for(int i = 1; i <= N; i++) {
      if(lca[i][j - 1]) {
        lca[i][j] = lca[lca[i][j - 1]][j - 1];
      }
    }
  }

  while(M--) {
    int u = scan(), v = scan(), k = scan();
    int l = lca_query(u, v);

    printf("%d\n", R_compres[query(1, N, root[u], root[v], root[l], root[lca[l][0]], k)]);
  }
}
