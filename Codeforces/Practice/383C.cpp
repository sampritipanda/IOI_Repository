#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 200000;

int A[MAX_N + 1];
int bit[MAX_N + 1];
vector<int> G[MAX_N + 1];
int S[MAX_N + 1], E[MAX_N + 1];
int depth[MAX_N + 1];
int timer = 0;

void dfs(int i, int p, int d) {
  S[i] = ++timer;
  depth[i] = d;

  for(auto v: G[i]) {
    if(v == p) continue;

    dfs(v, i, d + 1);
  }

  E[i] = timer;
}

int query(int i) {
  int ans = 0;
  while(i > 0) {
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

void update(int i, int v) {
  while(i <= MAX_N) {
    bit[i] += v;
    i += i & -i;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;
  for(int i = 1; i <= N; i++) cin >> A[i];

  for(int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dfs(1, 0, 0);

  while(M--) {
    int t; cin >> t;

    if(t == 2) {
      int x; cin >> x;
      int parity = (depth[x] % 2 == 0 ? 1 : -1);
      cout << A[x] + query(S[x]) * parity << endl;
    }
    else {
      int x, val; cin >> x >> val;

      if(depth[x] % 2 == 0) {
        update(S[x], +val);
        update(E[x] + 1, -val);
      }
      else {
        update(S[x], -val);
        update(E[x] + 1, +val);
      }
    }
  }
}
