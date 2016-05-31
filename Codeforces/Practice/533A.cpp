#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <climits>
#include <map>
#include <cassert>

using namespace std;

int H[500001];
multiset<int> S;
vector<int> G[500001];
int D[500001];
int vis[500001];
int segtree[4000001];
int lazy[4000001];
const int MAX_VAL = 1000000000;
int MAX_ID;
map<int, int> compres;
int timer = 0;

void propagate(int L, int R, int i) {
  if(lazy[i] == 0) return;

  segtree[i] += lazy[i];

  if(L != R) {
    lazy[2*i + 1] += lazy[i];
    lazy[2*i + 2] += lazy[i];
  }

  lazy[i] = 0;
}

int query(int L, int R, int i, int qL, int qR) {
  propagate(L, R, i);

  if(L > qR || R < qL) return INT_MAX/2;
  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;
  return min(query(L, mid, 2*i + 1, qL, qR), query(mid + 1, R, 2*i + 2, qL, qR));
}

void update(int L, int R, int i, int qL, int qR, int v) {
  propagate(L, R, i);

  if(L > qR || R < qL) return;
  if(qL <= L && R <= qR) {
    lazy[i] += v;
    propagate(L, R, i);
    return;
  }

  int mid = (L + R)/2;
  update(L, mid, 2*i + 1, qL, qR, v);
  update(mid + 1, R, 2*i + 2, qL, qR, v);
  segtree[i] = min(segtree[2*i + 1], segtree[2*i + 2]);
}

void dfs(int i, int p, int d) {
  d = min(d, H[i]);
  D[i] = d;

  for(int u: G[i]) {
    if(u == p) continue;

    G[u].erase(find(G[u].begin(), G[u].end(), i));
    dfs(u, i, d);
  }
}

void dfs2(int i, int d) {
  // update(1, MAX_ID, 0, 1, compres[D[i]], -1);
  // update(1, MAX_ID, 0, 1, compres[d], 1);
  int x = compres[D[i]], y = compres[d];
  if(x < y) update(1, MAX_ID, 0, x + 1, y, +1);
  else if(x > y) update(1, MAX_ID, 0, y + 1, x, -1);

  for(int u: G[i]) {
    dfs2(u, min(d, H[u]));
  }
}

void dfs2_erase(int i, int d) {
  // update(1, MAX_ID, 0, 1, compres[d], -1);
  // update(1, MAX_ID, 0, 1, compres[D[i]], 1);
  int x = compres[D[i]], y = compres[d];
  if(x < y) update(1, MAX_ID, 0, x + 1, y, -1);
  else if(x > y) update(1, MAX_ID, 0, y + 1, x, +1);

  for(int u: G[i]) {
    dfs2_erase(u, min(d, H[u]));
  }
}

int main() {
  int N; scanf("%d", &N);

  for(int i = 1; i <= N; i++) scanf("%d", &H[i]);

  for(int i = 0; i < N - 1; i++) {
    int a, b; scanf("%d %d", &a, &b);

    G[a].push_back(b);
    G[b].push_back(a);
  }

  int K; scanf("%d", &K);

  for(int i = 1; i <= K; i++) {
    int x; scanf("%d", &x);
    S.insert(x);
  }

  for(int i = 0; i <= N; i++) {
    D[i] = INT_MAX/2;
  }

  dfs(1, 0, INT_MAX/2);

  set<pair<int, int> > Q;
  Q.insert({D[1], 1});

  while(!S.empty() && !Q.empty()) {
    int M = *S.rbegin();
    auto it = Q.lower_bound({M, 0});

    if(it == Q.end()) break;

    S.erase(S.find(M));
    int u = it->second;
    Q.erase(it);
    vis[u] = true;

    for(int v: G[u]) {
      Q.insert({D[v], v});
    }
  }

  if(S.empty()) printf("0\n");
  else {
    int ans = INT_MAX/2;

    for(int x: S) compres[x];
    for(int i = 1; i <= N; i++) if(!vis[i]) compres[D[i]];
    for(int i = 1; i <= N; i++) if(!vis[i]) compres[H[i]];
    compres[MAX_VAL];

    for(auto it: compres) compres[it.first] = ++timer;

    MAX_ID = compres[MAX_VAL];
    assert(MAX_ID <= 1000001);

    for(int x: S) {
      update(1, MAX_ID, 0, 1, compres[x], -1);
    }

    for(int i = 1; i <= N; i++) {
      if(!vis[i]) update(1, MAX_ID, 0, 1, compres[D[i]], 1);
    }

    for(auto it: Q) {
      int u = it.second;
      dfs2(u, *S.rbegin());

      if(query(1, MAX_ID, 0, 1, MAX_ID) >= 0) {
        ans = min(ans, *S.rbegin() - H[u]);
      }

      dfs2_erase(u, *S.rbegin());
    }

    if(ans == INT_MAX/2) printf("-1\n");
    else printf("%d\n", ans);
  }
}
