#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

long long C[100001];
long long dp[100001];   // minimum time to complete task
long long dp2[100001];  // maximum time influenced by this element
long long dp3[100001];  // minimum value of increase which leads to >= 0 increase in dp2[i]
vector<int> G[100001];
bool vis[100001];
vector<int> order;

void dfs(int i) {
  if(vis[i]) return;
  vis[i] = true;

  for(auto v: G[i]) {
    dfs(v);
  }

  order.push_back(i);
}

int main() {
  int N, M; scanf("%d %d", &N, &M);
  for(int i = 1; i <= N; i++) scanf("%lld", &C[i]);

  while(M--) {
    int u, v; scanf("%d %d", &u, &v);
    G[u].push_back(v);
  }

  for(int i = 1; i <= N; i++) {
    if(!vis[i]) dfs(i);
  }
  reverse(order.begin(), order.end());

  long long ans = 0;
  for(int i = 0; i <= N; i++) dp[i] = 0;
  for(int i: order) {
    dp[i] += C[i];
    ans = max(ans, dp[i]);

    for(int v: G[i]) {
      dp[v] = max(dp[v], dp[i]);
    }
  }
  printf("%lld\n", ans);

  for(auto it = order.rbegin(); it != order.rend(); it++) {
    int i = *it;
    if(G[i].size() == 0) {
      dp2[i] = dp[i];
      dp3[i] = 0;
    }
    else {
      dp2[i] = -1;
      dp3[i] = LLONG_MAX/2;
      for(auto u: G[i]) {
        long long curr_inc = dp3[u] + (dp[u]-C[u]) - dp[i];
        if(dp2[i] == -1) {
          dp2[i] = dp2[u];
          dp3[i] = curr_inc;
        }
        else {
          if(dp3[i] - curr_inc > dp2[i] - dp2[u]) {
            dp2[i] = dp2[u];
            dp3[i] = curr_inc;
          }
        }
      }
    }
  }

  int Q; scanf("%d", &Q);
  while(Q--) {
    int u, d; scanf("%d %d", &u, &d);
    printf("%lld\n", max(ans, dp2[u] + d - dp3[u]));
  }
}
