#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

inline int scan() {
  int x = 0;
  char c = getchar();

  while(c < '0' || c > '9') {
    c = getchar();
  }

  while(c >= '0' && c <= '9') {
    x = (x<<1)+(x<<3)+c-'0';
    c = getchar();
  }
  return x;
}

const int MAX = 100000;
const int MAX_LOG = 17;

struct query {
  // t = year in which update occured
  // a, b = endpoints of path
  // k = index of requried vertext
  // y = (y+1..t) must be clear
  int t, a, b, k, y;
};

struct tree {
  int val;
  tree *left, *right;

  tree(int _val = 0, tree *_left = NULL, tree *_right = NULL) {
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

  tree* update(int L, int R, int v) {
    if(v > R || v < L) return this;

    tree *new_node = new tree(val + 1);

    if(L != R) {
      int mid = (L + R)/2;
      new_node->left = left->update(L, mid, v);
      new_node->right = right->update(mid + 1, R, v);
    }

    return new_node;
  }

  int query(int L, int R, int qL, int qR) {
    if(L > qR || R < qL) return 0;
    if(qL <= L && R <= qR) return val;

    int mid = (L + R)/2;
    return left->query(L, mid, qL, qR) + right->query(mid + 1, R, qL, qR);
  }
};

int N, M;
vector<int> G[MAX + 1];
int lca[MAX + 1][MAX_LOG];
int D[MAX + 1];
int U[MAX + 1];  // year in which city i was updated
vector<query> queries;
tree* root[MAX + 1];

inline int par(int u) {
  return lca[u][0];
}

void dfs(int i, int d) {
  D[i] = d;
  root[i] = root[par(i)]->update(1, M, U[i]);

  for(int v: G[i]) {
    dfs(v, d + 1);
  }
}

int lca_query(int u, int v) {
  if(D[u] > D[v]) swap(u, v);

  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(D[v] - (1 << j) >= D[u]) {
      v = lca[v][j];
    }
  }

  if(u == v) return u;

  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(lca[u][j] && lca[v][j] && lca[u][j] != lca[v][j]) {
      u = lca[u][j]; v = lca[v][j];
    }
  }

  if(lca[u][0] != lca[v][0]) {
    int test = 0;
  }
  assert(lca[u][0] == lca[v][0]);
  return lca[u][0];
}

inline int dist(int u, int v, int l) {
  return D[u] + D[v] - D[l] - D[par(l)];
}

// Number of free towns in path from u to v when lca == l   between years qL and qR
int path_query(int u, int v, int l, int qL, int qR) {
  // F(1, u) + F(1, v) - F(1, l) - F(1, par(l))

  int ans =   root[u]->query(1, M, qL, qR) + root[v]->query(1, M, qL, qR)
            - root[l]->query(1, M, qL, qR) - root[par(l)]->query(1, M, qL, qR);

  return dist(u, v, l) - ans;
}

// kth node on path from u -> v
int kth_node(int u, int v, int l, int k) {
  int half_dist = D[u] - D[l] + 1;
  if(k <= half_dist) {
    k--;
    int res = u;
    for(int i = MAX_LOG - 1; i >= 0; i--) {
      if(k & (1 << i))
        res = lca[res][i];
    }
    return res;
  }
  else {
    int full_dist = (D[u] - D[l] + 1) + (D[v] - D[l]);
    k = full_dist - k;
    int res = v;
    for(int i = MAX_LOG - 1; i >= 0; i--) {
      if(k & (1 << i))
        res = lca[res][i];
    }
    return res;
  }
}

int main() {
  N = scan();

  int king = -1;
  for(int i = 1; i <= N; i++) {
    lca[i][0] = scan();
    if(lca[i][0] == 0) {
      assert(king == -1);
      king = i;
    }
    G[par(i)].push_back(i);
  }

  M = scan();

  for(int i = 1; i <= M; i++) {
    int t = scan();

    if(t == 1) {
      int c = scan();
      U[c] = i;
    }
    else {
      int a = scan(), b = scan(), k = scan(), y = scan();
      queries.push_back({i, a, b, k, y});
    }
  }

  root[0] = new tree(); root[0]->build(1, M);
  dfs(king, 1);

  for(int j = 1; j < MAX_LOG; j++) {
    for(int i = 1; i <= N; i++) {
      if(lca[i][j - 1]) {
        lca[i][j] = lca[lca[i][j - 1]][j - 1];
      }
    }
  }

  for(auto it: queries) {
    int t = it.t, a = it.a, b = it.b, k = it.k, y = it.y;
    int l = lca_query(a, b);
    if(path_query(a, a, a, y + 1, t) == 1) k++;

    int X = 1, Y = dist(a, b, l);
    while(X < Y) {
      int mid = (X + Y)/2;
      int mid_node = kth_node(a, b, l, mid);

      int cnt = path_query(a, mid_node, lca_query(a, mid_node), y + 1, t);

      if(cnt >= k) {
        Y = mid;
      }
      else {
        X = mid + 1;
      }
    }

    assert(X != 1);
    if(X == dist(a, b, l)) {
      printf("-1\n");
    }
    else {
      printf("%d\n", kth_node(a, b, l, X));
    }
  }
}
