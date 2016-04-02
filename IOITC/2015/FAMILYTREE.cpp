#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>

using namespace std;

const int MAX = 1000000;
const int MAX_LOG = 20;

int P[MAX + 1];
vector<int> G[MAX + 1];
int D[MAX + 1];
vector<int> D_list[MAX + 1];
int S[MAX + 1], E[MAX + 1];
int timer = 0;
int lca[MAX_LOG][MAX + 1];

void dfs(int i, int d) {
  S[i] = ++timer;
  D[i] = d;
  D_list[d].push_back(S[i]);

  for(auto u: G[i]) {
    if(u == P[i]) continue;

    dfs(u, d + 1);
  }

  E[i] = timer;
}

// find pth ancestor of x
int lca_query(int x, int p) {
  for(int j = MAX_LOG - 1; j >= 0; j--) {
    if(p & (1 << j))
      x = lca[j][x];
  }

  return x;
}

int main() {
  int N; scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &P[i]);
    if(P[i] == 0) {
      P[i] = -1;
    }
    else {
      G[P[i]].push_back(i);
    }
  }

  for(int i = 1; i <= N; i++) {
    if(S[i] != 0) continue;
    dfs(i, 0);
  }

  memset(lca, -1, sizeof lca);

  for(int i = 1; i <= N; i++) {
    lca[0][i] = P[i];
  }
  for(int j = 1; j < MAX_LOG; j++) {
    for(int i = 1; i <= N; i++) {
      if(lca[j - 1][i] != -1) {
        lca[j][i] = lca[j - 1][lca[j - 1][i]];
      }
    }
  }

  for(int i = 0; i < N - 1; i++) {
    if(D_list[i].size() > 0) {
      sort(D_list[i].begin(), D_list[i].end());
    }
  }

  int M; scanf("%d", &M);
  while(M--) {
    int v, p; scanf("%d %d", &v, &p);

    if(D[v] < p) {
      printf("0\n");
      continue;
    }

    int anc = lca_query(v, p);
    int L = S[anc], R = E[anc];

    int depth = D[anc] + p;
    int ans = upper_bound(D_list[depth].begin(), D_list[depth].end(), R) - lower_bound(D_list[depth].begin(), D_list[depth].end(), L);

    printf("%d\n", ans - 1);
  }
}
