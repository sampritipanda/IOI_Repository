#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <climits>

using namespace std;

set<int> G[901];
int E[901][901];
int memo[901][901];
bool visited[901];
vector<pair<int, int> > edges;
queue<pair<int, int> > Q;

int main() {
  int N, M;

  while(scanf("%d %d", &N, &M) > 0) {
    for(int i = 0; i <= N; i++) {
      G[i].clear();
      for(int j = 0; j <= N; j++) {
        E[i][j] = 0;
        memo[i][j] = -1;
      }
    }

    edges.clear();
    while(M--) {
      int a, b; scanf("%d %d", &a, &b);
      E[a][b]++;
      G[a].insert(b);
      edges.push_back({a, b});
    }

    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) visited[i] = 0;
    }

    for(auto it: edges) {
      int a = it.first, b = it.second;
      printf("%d ", memo[a][b]);
    }
    printf("\n");
  }
}
