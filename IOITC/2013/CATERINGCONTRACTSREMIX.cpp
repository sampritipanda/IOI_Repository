// Catering Contracts Remix

#include <cstdio>
#include <map>
#include <climits>
#include <vector>

using namespace std;

vector<pair<int, int> > G[100005];
int stations[100005];
int parent[100005];
bool leaf[100005];
bool visited[100005];
int cost[100005]; // cost[i] = edge weight of parent[i] -> i
long long dp[100005][105];   // dp[i][j] = answer for subtree i with color j
long long dp2[100005];       // dp2[i] =  min(dp[i][j])
int N, M;

long long solve(int i, int j){
  if(dp[i][j] != -1) return dp[i][j];

  // Calculate dp2
  if(!visited[i]) {
    for(auto it: G[i]) {
      int v = it.first;
      if(v == parent[i]) continue;

      dp2[v] = LLONG_MAX/2;
      for(int x = 0; x <= M; x++) {
        dp2[v] = min(dp2[v], solve(v, x));
      }
    }
    visited[i] = true;
  }
  // end

  long long ans = 0;

  for(auto it: G[i]) {
    int v = it.first, w = it.second;
    if(v == parent[i]) continue;

    if(stations[v] == -1) {
      ans += min(dp2[v] + w, dp[v][j]);
    }
    else {
      ans += solve(v, stations[v]);
      if(stations[v] != j) ans += w;
    }
  }

  dp[i][j] = ans;
  return ans;
}

void dfs(int curr){
  leaf[curr] = true;

  for(auto it: G[curr]){
    int v = it.first, w = it.second;
    if(v == parent[curr]) continue;

    leaf[curr] = false;
    cost[v] = w;
    parent[v] = curr;

    dfs(v);
  }
}

int main() {
  for(int i = 0; i < 100005; i++) {
    for(int j = 0; j < 105; j++){
      dp[i][j] = -1;
    }
  }

  scanf("%d", &N);
  for(int i = 0; i < (N - 1); i++){
    int u, v, w; scanf("%d %d %d", &u, &v, &w);

    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }

  G[0].push_back({1, 0});

  M = 0;
  for(int i = 1; i <= N; i++){
    scanf("%d", &stations[i]);
    M = max(M, stations[i]);
  }

  parent[1] = 0;
  cost[1] = 0;
  dfs(1);

  printf("%lld\n", solve(0, 0));
}
