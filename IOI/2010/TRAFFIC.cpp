#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int P[1000000];
vector<int> G[1000000];
int S[1000000];
int ans[1000000];

void dfs(int i, int p) {
  S[i] = P[i];

  for(int u: G[i]) {
    if(u == p) continue;
    dfs(u, i);
    S[i] += S[u];
  }
}

void dfs2(int i, int p, int leftover) {
  ans[i] = leftover;

  for(int u: G[i]) {
    if(u == p) continue;

    ans[i] = max(ans[i], S[u]);
    dfs2(u, i, leftover + S[i] - S[u]);
  }
}

int main() {
  int N; scanf("%d", &N);

  for(int i = 0; i < N; i++) scanf("%d", &P[i]);

  for(int i = 0; i < N - 1; i++) {
    int u, v; scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dfs(0, -1);
  dfs2(0, -1, 0);

  printf("%ld\n", min_element(ans, ans + N) - ans);
}
