#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

vector<int> G[500001];
vector<int> leaves;

void dfs(int i, int p) {
  if(G[i].size() == 1) leaves.push_back(i);

  for(int j = 0; j < G[i].size(); j++) {
    int u = G[i][j];
    if(u == p) continue;
    dfs(u, i);
  }
}

int main() {
  int N; scanf("%d", &N);

  for(int i = 0; i < N - 1; i++) {
    int a, b; scanf("%d %d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(1, 0);

  int ans = (leaves.size() + 1)/2;

  printf("%d\n", ans);

  for(int i = 0; i < ans; i++) {
    assert((i + leaves.size()/2) < leaves.size());
    printf("%d %d\n", leaves[i], leaves[i + leaves.size()/2]);
  }
}
