#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

vector<pair<int, int> > G[1001];     // lifts
vector<int> G2[1001];     // reverse tracks
int dp[2001][1001]; // dp[i][j] = min points you can have if you are starting with i points at vertex j
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;

int dfs_num[1001], dfs_low[1001];
bool on_stack[1001];
int scc[1001];
vector<int> scc_list[1001];
stack<int> S;
int timer = 0;
vector<int> scc_graph[1001], scc_graph_rev[1001];
vector<int> topo;
bool vis[1001];

void dfs(int i) {
  dfs_num[i] = dfs_low[i] = ++timer;
  S.push(i);
  on_stack[i] = true;

  for(int ind = 0; ind < G2[i].size(); ind++) {
    int u = G2[i][ind];
    if(!dfs_num[u]) {
      dfs(u);
    }

    if(on_stack[u]) {
      dfs_low[i] = min(dfs_low[i], dfs_low[u]);
    }
  }

  if(dfs_num[i] == dfs_low[i]) {
    while(true) {
      int v = S.top(); S.pop();
      on_stack[v] = false;
      scc[v] = i;
      scc_list[i].push_back(v);
      if(v == i) break;
    }
  }
}

void dfs2(int i) {
  if(vis[i]) return;
  vis[i] = true;

  for(int ind = 0; ind < scc_graph[i].size(); ind++) {
    int u = scc_graph[i][ind];
    dfs2(u);
  }

  topo.push_back(i);
}

int main() {
  int N, N_; scanf("%d %d", &N, &N_);

  int K; scanf("%d", &K);
  while(K--) {
    int u, v; scanf("%d %d", &u, &v);
    G2[v].push_back(u);
  }

  int M; scanf("%d", &M);
  while(M--) {
    int u, v, r; scanf("%d %d %d", &u, &v, &r);
    G[u].push_back(make_pair(v, r));
  }

  int B, S; scanf("%d %d", &B, &S);

  for(int i = 1; i <= N; i++) {
    if(dfs_num[i]) continue;
    dfs(i);
  }

  for(int i = 1; i <= N; i++) {
    for(int ind = 0; ind < G2[i].size(); ind++) {
      int u = G2[i][ind];
      scc_graph[scc[i]].push_back(scc[u]);
      scc_graph_rev[scc[u]].push_back(scc[i]);
    }
  }

  for(int i = 1; i <= N; i++) {
    if(vis[i]) continue;
    if(scc[i] != i) continue;
    dfs2(i);
  }
  reverse(topo.begin(), topo.end());


  for(int i = 0; i <= S; i++) {
    for(int j = 1; j <= N; j++) {
      dp[i][j] = INT_MAX/2;
    }
  }

  for(int i = 0; i <= S; i++) {
    for(int j = 1; j <= N; j++) {
      if(j <= N_) dp[i][j] = min(dp[i][j], i);
      for(int ind = 0; ind < G[j].size(); ind++) {
        int u = G[j][ind].first, r = G[j][ind].second;
        if(i - r >= 0) dp[i][j] = min(dp[i][j], dp[i - r][u]);
      }
    }

    for(int ind = 0; ind < topo.size(); ind++) {
      int scc_id = topo[ind];
      int curr_min = INT_MAX/2;
      for(int ind2 = 0; ind2 < scc_graph_rev[scc_id].size(); ind2++) {
        int scc_id2 = scc_graph_rev[scc_id][ind2];
        curr_min = min(curr_min, dp[i][scc_list[scc_id2][0]]);
      }
      for(int ind2 = 0; ind2 < scc_list[scc_id].size(); ind2++) {
        int j = scc_list[scc_id][ind2];
        curr_min = min(curr_min, dp[i][j]);
      }
      for(int ind2 = 0; ind2 < scc_list[scc_id].size(); ind2++) {
        int j = scc_list[scc_id][ind2];
        dp[i][j] = curr_min;
      }
    }
  }

  printf("%d\n", dp[S][B]);
}
