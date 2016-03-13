#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int> > G;
int start_time[100000], end_time[100000];
int timer = 0;
long long segtree[400001], lazy[400001];

void propagate(int L, int R, int i) {
  if(lazy[i] != 0) {
    segtree[i] += (R - L + 1) * lazy[i];

    if(L != R) {
      lazy[2*i + 1] += lazy[i];
      lazy[2*i + 2] += lazy[i];
    }
    lazy[i] = 0;
  }
}

void update(int L, int R, int i, int qL, int qR, long long inc) {
  propagate(L, R, i);

  if(L > R) return;
  if(L > qR || R < qL) return;

  if(qL <= L && R <= qR) {
    lazy[i] += inc;
    propagate(L, R, i);
    return;
  }

  int mid = (L + R)/2;
  update(L, mid, 2*i + 1, qL, qR, inc);
  update(mid + 1, R, 2*i + 2, qL, qR, inc);
  segtree[i] = segtree[2*i + 1] + segtree[2*i + 2];
}

long long query(int L, int R, int i, int qL, int qR) {
  propagate(L, R, i);

  if(L > R) return 0;
  if(L > qR || R < qL) return 0;

  if(qL <= L && R <= qR) return segtree[i];

  int mid = (L + R)/2;
  return query(L, mid, 2*i + 1, qL, qR) + query(mid + 1, R, 2*i + 2, qL, qR);
}

void dfs(int i, int p) {
  start_time[i] = ++timer;

  for(auto v: G[i]) {
    if(v != p) {
      dfs(v, i);
    }
  }

  end_time[i] = timer;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  G.resize(N);

  for(int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dfs(0, -1);

  int Q; cin >> Q;

  while(Q--) {
    char type; cin >> type;

    if(type == 'A') {
      int v; long long inc; cin >> v >> inc;
      update(1, N, 0, start_time[v], end_time[v], inc);
    }
    else {
      int v; cin >> v;
      cout << query(1, N, 0, start_time[v], start_time[v]) << endl;
    }
  }
}
