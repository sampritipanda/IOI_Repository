#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <climits>

using namespace std;

vector<int> G[500001];  // Out-Graph
vector<int> G2[500001]; // In-Graph
int dp[500001];    // Longest path ending at i
int dp2[500001];   // Longest path starting at i
int dp2_2[500001]; // 2nd Longest path starting at i
int nxt[500001];  // Next node in longest path starting at i
vector<int> top;  // Topological Order
bool vis[500001];
set<int> anc[500001];  // Start Nodes which have i on their longest path
vector<int> start_nodes;  // Nodes with indegree 0

void dfs(int i) {
  if(vis[i]) return;
  vis[i] = true;

  for(int j = 0; j < G[i].size(); j++) {
    int u = G[i][j];
    dfs(u);
  }

  top.push_back(i);
}

int main() {
  int N, M; scanf("%d %d", &N, &M);

  while(M--) {
    int a, b; scanf("%d %d", &a, &b);
    G[a].push_back(b);
    G2[b].push_back(a);
  }

  for(int i = 1; i <= N; i++) {
    sort(G[i].begin(), G[i].end());
    G[i].resize(unique(G[i].begin(), G[i].end()) - G[i].begin());

    sort(G2[i].begin(), G2[i].end());
    G2[i].resize(unique(G2[i].begin(), G2[i].end()) - G2[i].begin());
  }

  for(int i = 1; i <= N; i++) {
    if(vis[i]) continue;
    dfs(i);
  }
  reverse(top.begin(), top.end());

  for(int j = 0; j < top.size(); j++) {
    int u = top[j];
    if(G2[u].size() == 0) {
      dp[u] = 0;
    }
    else {
      for(int k = 0; k < G2[u].size(); k++) {
        int p = G2[u][k];
        dp[u] = max(dp[u], dp[p] + 1);
      }
    }
  }

  for(int j = top.size() - 1; j >= 0; j--) {
    int u = top[j];
    if(G[u].size() == 0) {
      dp2[u] = 0;
      dp2_2[u] = -1;
    }
    else {
      for(int k = 0; k < G[u].size(); k++) {
        int v = G[u][k];

        if(dp2[v] + 1 > dp2[u]) {
          if(dp2[u] > 0) dp2_2[u] = dp2[u];
          dp2[u] = dp2[v] + 1;
          nxt[u] = v;
        }
        else if(dp2[v] + 1 > dp2_2[u]) {
          dp2_2[u] = dp2[v] + 1;
        }
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    if(G2[i].size() == 0) {
      start_nodes.push_back(i);

      int j = i;
      while(j) {
        anc[j].insert(i);
        j = nxt[j];
      }
    }
  }

  int ans = INT_MAX/2, ans_node = -1;

  for(int i = 1; i <= N; i++) {
    int curr = 0;
    for(int j = 0; j < G[i].size(); j++) {
      int u = G[i][j];
      curr = max(curr, dp2[u]);
    }
    for(int j = 0; j < G2[i].size(); j++) {
      int p = G2[i][j];
      curr = max(curr, dp[p]);
      if(nxt[p] != i) continue;
      curr = max(curr, dp[p] + dp2_2[p]);
    }

    for(int j = 0; j < start_nodes.size(); j++) {
      int u = start_nodes[j];
      if(anc[i].count(u) == 0) curr = max(curr, dp2[u]);
    }

    if(curr < ans) {
      ans = curr;
      ans_node = i;
    }
  }
  printf("%d %d\n", ans_node, ans);
}
