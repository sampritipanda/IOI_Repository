// BAD CODE ALERT

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>

using namespace std;

vector<int> G[500001];
int S[500001], E[500001];
// Segtree 0: Latest time when node was filled
// Segtree 1: Latest time when node was cleared
int segtree[2000001][2];
int lazy[2000001][2];

void propagate(int L, int R, int i, int j) {
  if(lazy[i][j] != 0) {
    segtree[i][j] = lazy[i][j];

    if(L != R) {
      lazy[2*i + 1][j] = lazy[i][j];
      lazy[2*i + 2][j] = lazy[i][j];
    }

    lazy[i][j] = 0;
  }
}

void update(int L, int R, int i, int qL, int qR, int v, int j) {
  propagate(L, R, i, j);

  if(L > qR || R < qL) return;

  if(qL <= L && R <= qR) {
    lazy[i][j] = v;
    propagate(L, R, i, j);
    return;
  }

  int mid = (L + R)/2;
  update(L, mid, 2*i + 1, qL, qR, v, j);
  update(mid + 1, R, 2*i + 2, qL, qR, v, j);

  segtree[i][j] = max(segtree[2*i + 1][j], segtree[2*i + 2][j]);
}

int query(int L, int R, int i, int qL, int qR, int j) {
  propagate(L, R, i, j);

  if(L > qR || R < qL) return -1;

  if(qL <= L && R <= qR) {
    return segtree[i][j];
  }

  int mid = (L + R)/2;

  return max(query(L, mid, 2*i + 1, qL, qR, j), query(mid + 1, R, 2*i + 2, qL, qR, j));
}

int timer = 0;
void dfs(int i, int p) {
  S[i] = ++timer;

  for(auto v: G[i]) {
    if(v == p) continue;
    dfs(v, i);
  }

  E[i] = timer;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dfs(1, 0);

  timer = 0;
  int Q; cin >> Q;
  while(Q--) {
    int t, v; cin >> t >> v;

    if(t == 1) {
      update(1, N, 0, S[v], E[v], ++timer, 0);
    }
    else if(t == 2) {
      update(1, N, 0, S[v], S[v], ++timer, 1);
    }
    else {
      int fillTime = query(1, N, 0, S[v], S[v], 0);
      int clearTime = query(1, N, 0, S[v], E[v], 1);
      cout << (fillTime > clearTime) << endl;
    }
  }
}
