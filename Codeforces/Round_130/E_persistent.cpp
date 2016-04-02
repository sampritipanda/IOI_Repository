#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>

using namespace std;

struct tree {
  int val = 0;
  tree *left, *right;

  tree(int _val = 0, tree* _left = NULL, tree* _right = NULL) {
    left = _left;
    right = _right;
    val = _val;
  }

  void build(int L, int R) {
    if(L == R) return;

    int mid = (L + R)/2;
    left = new tree(); left->build(L, mid);
    right = new tree(); right->build(mid + 1, R);
  }

  int query(int L, int R, int d) {
    if(L == R) return val;

    int mid = (L + R)/2;
    if(d <= mid) {
      return left->query(L, mid, d);
    }
    else {
      return right->query(mid + 1, R, d);
    }
  }

  tree* update(int L, int R, int d) {
    if(d < L || d > R) return this;

    tree* new_tree = new tree(val + 1);
    if(L != R) {
      int mid = (L + R)/2;
      new_tree->left = left->update(L, mid, d);
      new_tree->right = right->update(mid + 1, R, d);
    }

    return new_tree;
  }
};

const int MAX = 100000;
const int MAX_LOG = 17;

int P[MAX + 1];
vector<int> G[MAX + 1];
int D[MAX + 1];
int S[MAX + 1], E[MAX + 1], rev_S[MAX + 1];
int timer = 0;
tree* root[MAX + 1];
int lca[MAX_LOG][MAX + 1];

void dfs(int i, int d) {
  S[i] = ++timer;
  rev_S[S[i]] = i;
  D[i] = d;

  for(auto u: G[i]) {
    if(u == P[i]) continue;

    dfs(u, d + 1);
  }

  E[i] = timer;
}

// find pth ancestor of x
int lca_query(int x, int p) {
  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(p & (1 << j))
      x = lca[j][x];
  }

  return x;
}

int main() {
  int N; scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &P[i]);
    if(P[i] == 0) {
      P[i] = -1;
    }
    else {
      G[P[i]].push_back(i);
    }
  }

  for(int i = 1; i <= N; i++) {
    if(S[i] != 0) continue;
    dfs(i, 0);
  }

  root[0] = new tree(); root[0]->build(0, N - 1);
  for(int i = 1; i <= N; i++) {
    root[i] = root[i - 1]->update(0, N - 1, D[rev_S[i]]);
  }

  memset(lca, -1, sizeof lca);

  for(int i = 1; i <= N; i++) {
    lca[0][i] = P[i];
  }
  for(int j = 1; j < MAX_LOG; j++) {
    for(int i = 1; i <= N; i++) {
      if(lca[j - 1][i] != -1) {
        lca[j][i] = lca[j - 1][lca[j - 1][i]];
      }
    }
  }

  int M; scanf("%d", &M);
  while(M--) {
    int v, p; scanf("%d %d", &v, &p);

    if(D[v] < p) {
      printf("0 ");
      continue;
    }

    int anc = lca_query(v, p);
    int L = S[anc], R = E[anc];

    int depth = D[anc] + p;
    int ans = root[R]->query(0, N - 1, depth) - root[L - 1]->query(0, N - 1, depth);

    printf("%d ", ans - 1);
  }
  printf("\n");
}
