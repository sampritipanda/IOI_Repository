#include <bits/stdc++.h>

using namespace std;

int N, Q;
vector<int> G[100000 + 111];
int A[100000 + 100];

void dfs(int u, int p, int x) {
  A[u] = x;

  for(int v:G[u]){ if(v!=p) {
    dfs(v, u, x^1);
  }}
}

int main() {
  scanf("%d", &N);
  for(int i = 1; i < N; i++) {
    int u,v; scanf("%d %d", &u,&v);
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  dfs(1, 0, 0);

  scanf("%d", &Q);
  while(Q--) {
    int a,b; scanf("%d %d", &a,  &b);
    if(A[a]^A[b] == 1) {
      printf("Odd\n");
    }
    else {
      printf("Even\n");
    }
  }
}
