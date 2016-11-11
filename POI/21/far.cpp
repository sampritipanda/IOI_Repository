// FarmCraft

#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define MAX 500000

int C[MAX + 1];
vector<int> G[MAX + 1];
int sz[MAX + 1];
int dp[MAX + 1];

bool compare(pair<int, pair<int, int> > A, pair<int, pair<int, int> > B) {
  return (A.second.first - 2 * A.second.second) > (B.second.first - 2 * B.second.second);
}

void solve(int u, int p) {
  sz[u] = 1;
  for(int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if(v == p) continue;
    solve(v, u);
    sz[u] += sz[v];
  }

  vector<pair<int, pair<int, int> > > A;     // {id, {dp_val, sz}}
  for(int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if(v == p) continue;
    A.push_back(make_pair(v, make_pair(dp[v], sz[v])));
  }
  sort(A.begin(), A.end(), compare);

  dp[u] = 0;
  int sum = 0;
  for(int i = 0; i < A.size(); i++) {
    int v = A[i].first;
    dp[u] = max(dp[u], sum + 1 + dp[v]);
    sum += 2 * sz[v];
  }

  if(u == 1) {
    dp[u] = max(dp[u], 2 * (sz[u] - 1) + C[u]);
  }
  else {
    dp[u] = max(dp[u], C[u]);
  }
}

int main() {
  int N; scanf("%d", &N);

  for(int i = 1; i <= N; i++) scanf("%d", &C[i]);

  for(int i = 0; i < N - 1; i++) {
    int u, v; scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  solve(1, -1);

  printf("%d\n", dp[1]);
}
