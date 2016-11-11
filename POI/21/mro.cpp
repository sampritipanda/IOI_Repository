// Ant colony

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 1000000

long long M[MAX + 1];
vector<int> G[MAX + 1];
int P[MAX + 1];
long long prod[MAX + 1];

long long mult(long long a, long long b) {
  return min(a * b, 1000000000LL + 1);
}

void dfs(int u, int p) {
  P[u] = p;
  for(int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if(v == p) continue;
    dfs(v, u);
  }
}

void solve_b(int u, long long curr = 1) {
  if(G[u].size() == 1) {
    prod[u] = curr;
    return;
  }

  curr = mult(curr, G[u].size() - 1);
  for(int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if(v == P[u]) continue;
    solve_b(v, curr);
  }
}

void solve_a(int u, int b, long long curr = 1) {
  if(G[u].size() == 1) {
    prod[u] = curr;
    return;
  }
  curr = mult(curr, G[u].size() - 1);
  for(int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if(v == P[u] || v == b) continue;
    solve_a(v, b, curr);
  }
}

int main() {
  int N, groups; long long K; scanf("%d %d %lld", &N, &groups, &K);

  for(int i = 0; i < groups; i++) scanf("%lld", &M[i]);

  int a = -1, b = -1;
  for(int i = 0; i < N - 1; i++) {
    int u, v; scanf("%d %d", &u, &v);
    if(a == -1) a = u, b = v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dfs(a, -1);
  solve_b(b);
  solve_a(a, b);

  sort(M, M + groups);

  long long cnt = 0;
  for(int i = 1; i <= N; i++) {
    if(G[i].size() == 1) {
      long long lo = prod[i] * K, hi = prod[i] * (K + 1) - 1;
      cnt += upper_bound(M, M + groups, hi) - lower_bound(M, M + groups, lo);
    }
  }

  printf("%lld\n", cnt * K);
}
