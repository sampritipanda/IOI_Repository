#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int Q_K[1000001];
vector<int> G[1000001];
int L[1000001];
int ans[1000001];

void dfs(int i, int h) {
  L[h]++;

  for(int j = 0; j < G[i].size(); j++) {
    int u = G[i][j];
    dfs(u, h + 1);
  }
}

int main() {
  int N, Q; scanf("%d %d", &N, &Q);

  for(int i = 1; i <= Q; i++) scanf("%d", &Q_K[i]);

  for(int i = 2; i <= N; i++) {
    int p; scanf("%d", &p);
    G[p].push_back(i);
  }

  dfs(1, 0);

  int M;
  int width = 0;
  for(M = 0; M <= N; M++) {
    if(!L[M]) break;
    width = max(width, L[M]);
  }
  M--;

  for(int q = 1; q <= Q; q++) {
    int K = Q_K[q];
    if(width <= K) ans[K] = M + 1;

    if(ans[K] == 0) {
      int rem = 0;
      for(int i = 0; i <= M; i++) {
        ans[K]++;
        rem += L[i] - K;
        if(rem < 0) rem = 0;
      }
      ans[K] += (rem + K - 1)/K;
    }

    printf("%d", ans[K]);
    if(q == Q) printf("\n");
    else printf(" ");
  }
}
