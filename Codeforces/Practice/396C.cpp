#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

vector<int> G[300001];
int S[300001], E[300001], D[300001];
int timer = 0;

// {x1 + x2 + ... + xn, k1 + k2 + ... + kn,  d1*k1 + d2*k2 + ... + dn*kn}
struct node {
  int X, K_sum, DK_sum;

  void clear() {
    X = 0;
    K_sum = 0;
    DK_sum = 0;
  }

  node() {
    clear();
  }

  node(int _X, int _K_sum, int _DK_sum) {
    X = _X;
    K_sum = _K_sum;
    DK_sum = _DK_sum;
  }

  bool empty() {
    return (X == 0 && K_sum == 0 && DK_sum == 0);
  }
};

node segtree[1200001];
node lazy[1200001];

void dfs(int i, int p, int d) {
  S[i] = ++timer;
  D[i] = d;

  for(auto u: G[i]) {
    if(u == p) continue;
    dfs(u, i, d + 1);
  }

  E[i] = timer;
}

inline int reduce(int x) {
  while(x < 0) x += MOD;
  return x % MOD;
}

inline node merge(node L, node R) {
  node N;
  N.X = (L.X + R.X) % MOD;
  N.K_sum = (L.K_sum + R.K_sum) % MOD;
  N.DK_sum = (L.DK_sum + R.DK_sum) % MOD;
  return N;
}

void propagate(int L, int R, int i) {
  if(!lazy[i].empty()) {
    segtree[i] = merge(segtree[i], lazy[i]);

    if(L != R) {
      lazy[2*i + 1] = merge(lazy[2*i + 1], lazy[i]);
      lazy[2*i + 2] = merge(lazy[2*i + 2], lazy[i]);
    }

    lazy[i].clear();
  }
}

node query(int L, int R, int i, int v) {
  propagate(L, R, i);

  if(L == R) return segtree[i];

  int mid = (L + R)/2;
  if(v <= mid) return query(L, mid, 2*i + 1, v);
  else return query(mid + 1, R, 2*i + 2, v);
}

void update(int L, int R, int i, int qL, int qR, int x, int d, int k) {
  if(L > R || L > qR || R < qL) return;

  propagate(L, R, i);

  if(qL <= L && R <= qR) {
    lazy[i] = merge(lazy[i], {x, k, (1LL * d * k) % MOD});
    propagate(L, R, i);
    return;
  }

  int mid = (L + R)/2;
  update(L, mid, 2*i + 1, qL, qR, x, d, k);
  update(mid + 1, R, 2*i + 2, qL, qR, x, d, k);
}

int main() {
  int N; scanf("%d", &N);
  for(int i = 2; i <= N; i++) {
    int x; scanf("%d", &x);
    G[i].push_back(x);
    G[x].push_back(i);
  }

  dfs(1, 0, 0);

  int M; scanf("%d", &M);

  while(M--) {
    int type; scanf("%d", &type);

    if(type == 1) {
      int v, x, k; scanf("%d %d %d", &v, &x, &k);
      update(1, N, 0, S[v], E[v], x, D[v], k);
    }
    else {
      int v; scanf("%d", &v);
      node curr = query(1, N, 0, S[v]);

      int sub = ((1LL * D[v] * curr.K_sum) % MOD) - curr.DK_sum;
      sub = reduce(sub);

      int ans = curr.X - sub;
      printf("%d\n", (int)reduce(ans));
    }
  }
}
