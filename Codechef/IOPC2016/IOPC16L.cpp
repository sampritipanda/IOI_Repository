#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
bool vis[100000];
vector<int> G[100000];
vector<int> A;

int find() {
  for(int i = 0; i < N; i++) vis[i] = false;

  for(int u: A) {
    if(vis[u]) continue;

    for(int v: G[u]) {
      if(vis[v]) continue;

      vis[u] = true; vis[v] = true;
      break;
    }
  }

  int cnt = 0;
  for(int i = 0; i < N; i++) {
    if(vis[i]) cnt++;
  }
  return cnt;
}

int main() {
  int M, K; scanf("%d %d %d", &N, &M, &K);

  while(M--) {
    int u, v; scanf("%d %d", &u, &v); u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  for(int i = 0; i < N; i++) A.push_back(i);

  if(find() < 2*K) printf("Case 1\n");
  else printf("Case 2\n");
}
