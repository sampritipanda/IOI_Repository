#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <cstring>

using namespace std;

vector<vector<pair<int, int> > > G;
vector<int> dist;
int W[10000];
int dp[1001][10000];

int main() {
  int T; scanf("%d", &T);

  while(T--) {
    G.clear(); dist.clear();

    int N, M, D; scanf("%d %d %d", &N, &M, &D);

    G.resize(N); dist.resize(N, INT_MAX/2);

    while(M--) {
      int u, v, w; scanf("%d %d %d", &u, &v, &w);

      G[u].push_back({v, w});
      G[v].push_back({u, w});
    }

    set<pair<int, int> > Q;

    Q.insert({0, 0});
    dist[0] = 0;

    while(!Q.empty()) {
      auto it = *Q.begin(); Q.erase(Q.begin());
      int u = it.second, d = it.first;

      for(auto it: G[u]) {
        int v = it.first, cost = it.second;

        if(dist[u] + cost < dist[v]) {
          if(dist[v] != INT_MAX/2) {
            Q.erase({dist[v], v});
          }
          dist[v] = dist[u] + cost;
          Q.insert({dist[v], v});
        }
      }
    }

    W[0] = 0;
    for(int i = 1; i < N; i++) scanf("%d", &W[i]);
    for(int i = 0; i < N; i++) dist[i] *= 2;

    for(int i = 0; i < N; i++) dp[0][i] = 0;
    for(int i = 1; i <= D; i++) dp[i][0] = 0;

    for(int i = 1; i <= D; i++) {
      for(int j = 1; j < N; j++) {
        dp[i][j] = dp[i][j - 1];
        if(i >= dist[j]) {
          dp[i][j] = max(dp[i][j], W[j] + dp[i - dist[j]][j - 1]);
        }
      }
    }

    int ans = 0;
    for(int i = 1; i <= D; i++) ans = max(ans, dp[i][N - 1]);
    printf("%d\n", ans);
  }
}
