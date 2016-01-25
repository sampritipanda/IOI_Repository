#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

char C[400000];
long long segtree[1200000];
char lazy[1200000];
int start_t[400000], end_t[400000];
int rev_start[400000];
int timer = -1;
vector<vector<int> > G;

void dfs(int i, int parent) {
  start_t[i] = ++timer;
  rev_start[start_t[i]] = i;

  for(auto v: G[i]) {
    if(v != parent) dfs(v, i);
  }

  end_t[i] = timer;
}

void propagate(int L, int R, int i) {
  if(lazy[i] != 0) {
    segtree[i] = 1LL << lazy[i];
    if(L != R) {
      lazy[2*i + 1] = lazy[i];
      lazy[2*i + 2] = lazy[i];
    }
    lazy[i] = 0;
  }
}

void build_tree(int L, int R, int i) {
  if(L == R) {
    segtree[i] = 1LL << C[rev_start[L]];
    return;
  }

  int mid = (L + R)/2;
  build_tree(L, mid, 2*i + 1);
  build_tree(mid + 1, R, 2*i + 2);
  segtree[i] = segtree[2*i + 1] | segtree[2*i + 2];
}

long long query(int L, int R, int A, int B, int i) {
  propagate(L, R, i);

  if(L > B || R < A) return 0;
  if(A <= L && R <= B) return segtree[i];

  int mid = (L + R)/2;
  return query(L, mid, A, B, 2*i + 1) | query(mid + 1, R, A, B, 2*i + 2);
}

void update(int L, int R, int A, int B, int i, int c) {
  propagate(L, R, i);
  if(L > B || R < A) return;

  if(A <= L && R <= B) {
    lazy[i] = c;
    propagate(L, R, i);
    return;
  }

  int mid = (L + R)/2;
  update(L, mid, A, B, 2*i + 1, c);
  update(mid + 1, R, A, B, 2*i + 2, c);
  segtree[i] = segtree[2*i + 1] | segtree[2*i + 2];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  G.resize(N);

  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    C[i] = char(x);
  }

  for(int i = 0; i < N - 1; i++) {
    int x, y; cin >> x >> y; x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  dfs(0, -1);
  build_tree(0, N - 1, 0);

  while(M--) {
    int t; cin >> t;

    if(t == 1) {
      int v, c; cin >> v >> c; v--;
      update(0, N - 1, start_t[v], end_t[v], 0, c);
    }
    else {
      int v; cin >> v; v--;
      long long ans = query(0, N - 1, start_t[v], end_t[v], 0);
      cout << __builtin_popcountll(ans) << endl;
    }
  }
}

