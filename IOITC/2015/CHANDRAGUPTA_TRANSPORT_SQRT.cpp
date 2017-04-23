#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int BLOCK_SIZE = 300;
vector<int> G[100001];
int S[100001], E[100001], depth[100001], P[100001];
long long V[100001];
long long dp[100001];
int upd_A[100001], upd_D[100001];
int timer = 0;

void dfs(int i, int p, int d) {
  S[i] = ++timer;
  depth[i] = d;
  P[i] = p;

  for(int u: G[i]) {
    if(u == p) continue;
    dfs(u, i, d + 1);
  }

  E[i] = timer;
}

void recalculate(int i, long long sum, long long d_sum) {
  sum += upd_A[i] + d_sum;
  d_sum += upd_D[i];
  V[i] += sum;
  dp[i] = dp[P[i]] + V[i];
  upd_A[i] = upd_D[i] = 0;

  for(int u: G[i]) {
    if(u == P[i]) continue;
    recalculate(u, sum, d_sum);
  }
}

int main() {
  int N, Q; scanf("%d %d", &N, &Q);

  for(int i = 0; i < N - 1; i++) {
    int u, v; scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  for(int i = 1; i <= N; i++) scanf("%lld", &V[i]);

  dfs(1, 0, 0);
  recalculate(1, 0, 0);

  int buffer = 0;
  vector<pair<int, pair<int, int> > > updates;
  while(Q--) {
    int t; scanf("%d", &t);

    if(t == 1) {
      int v, a, d; scanf("%d %d %d", &v, &a, &d);
      buffer++;
      upd_A[v] += a;
      upd_D[v] += d;
      updates.push_back({v, {a, d}});
    }
    else {
      int u; scanf("%d", &u);
      long long ans = dp[u];
      for(auto it: updates) {
        int v = it.first, a = it.second.first, d = it.second.second;
        if(S[v] <= S[u] && S[u] <= E[v]) {
          long long dist = depth[u] - depth[v];
          ans += ((dist + 1) * (2 * a + dist * d))/2;
        }
      }
      printf("%lld\n", ans);
    }

    if(buffer == BLOCK_SIZE) {
      recalculate(1, 0, 0);
      updates.clear();
      buffer = 0;
    }
  }
}
