#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> G[100001];
int V[100001];
int S[100001], E[100001];
long long D[100001];
long long cost[100001];
int timer = 0;

struct node {
  long long A, AD, K, KD, KD2;

  // A = (a1 + a2)
  // AD = (a1 d1 + a2 d2)
  // K = (k1 + k2)
  // KD = (k1 d1 + k2 d2)
  // KD2 = (k1 d1^2 + k2 d2^2)

  void clear() {
    A = 0;
    AD = 0;
    K = 0;
    KD = 0;
    KD2 = 0;
  }

  node() {
    clear();
  }

  node(long long _A, long long _AD, long long _K, long long _KD, long long _KD2) {
    A = _A;
    AD = _AD;
    K = _K;
    KD = _KD;
    KD2 = _KD2;
  }

  bool empty() {
    return (A == 0 && AD == 0 && K == 0 && KD == 0);
  }
};

node segtree[400001];
node lazy[400001];

void dfs(int i, int p, long long d, long long cst) {
  S[i] = ++timer;
  D[i] = d;
  cost[i] = cst + V[i];

  for(auto u: G[i]) {
    if(u == p) continue;
    dfs(u, i, d + 1, cost[i]);
  }

  E[i] = timer;
}

inline node merge(node L, node R) {
  node N;
  N.A = L.A + R.A;
  N.AD = L.AD + R.AD;
  N.K = L.K + R.K;
  N.KD = L.KD + R.KD;
  N.KD2 = L.KD2 + R.KD2;
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

void update(int L, int R, int i, int qL, int qR, long long a, long long d, long long k) {
  if(L > R || L > qR || R < qL) return;

  propagate(L, R, i);

  if(qL <= L && R <= qR) {
    lazy[i] = merge(lazy[i], {a, a * d, k, k * d, k * d * d});
    propagate(L, R, i);
    return;
  }

  int mid = (L + R)/2;
  update(L, mid, 2*i + 1, qL, qR, a, d, k);
  update(mid + 1, R, 2*i + 2, qL, qR, a, d, k);
}

int main() {
  int N, M; scanf("%d %d", &N, &M);
  for(int i = 0; i < N - 1; i++) {
    int u, v; scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  for(int i = 1; i <= N; i++) scanf("%d", &V[i]);

  dfs(1, 0, 0, 0);

  while(M--) {
    int type; scanf("%d", &type);

    if(type == 1) {
      int v, a, k; scanf("%d %d %d", &v, &a, &k);
      update(1, N, 0, S[v], E[v], a, D[v], k);
    }
    else {
      int v; scanf("%d", &v);
      node curr = query(1, N, 0, S[v]);

      long long ans = (D[v] + 1) * curr.A - curr.AD + (D[v] * D[v] * curr.K - 2 * D[v] * curr.KD + D[v] * curr.K - curr.KD + curr.KD2)/2;
      printf("%lld\n", ans + cost[v]);
    }
  }
}
