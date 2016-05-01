#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <climits>

using namespace std;

vector<int> G[3001];
int D[3001][3001];
int vis[3001];
queue<pair<int, int> > Q;
int dfs_num[3001], dfs_low[3001];
bool on_stack[3001];
int scc[3001];
stack<int> S;
int timer = 0;
int N;

void bfs(int start) {
  for(int i = 1; i <= N; i++) {
    vis[i] = false;
    D[start][i] = INT_MAX/4;
  }
  Q.push({start, 0});

  while(!Q.empty()) {
    int u = Q.front().first, d = Q.front().second;
    Q.pop();

    if(vis[u]) continue;
    vis[u] = true;

    D[start][u] = d;

    for(int v: G[u]) {
      Q.push({v, d + 1});
    }
  }
}

void dfs(int i) {
  dfs_num[i] = dfs_low[i] = ++timer;
  on_stack[i] = true;
  S.push(i);

  for(int u: G[i]) {
    if(dfs_num[u] == 0) {
      dfs(u);
    }

    if(on_stack[u]) {
      dfs_low[i] = min(dfs_low[i], dfs_low[u]);
    }
  }

  if(dfs_num[i] == dfs_low[i]) {
    while(true) {
      int u = S.top(); S.pop();
      scc[u] = i;
      on_stack[u] = false;
      if(u == i) break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int M; cin >> N >> M;

  while(M--) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
  }

  for(int i = 1; i <= N; i++) bfs(i);

  for(int i = 1; i <= N; i++) {
    if(dfs_num[i]) continue;
    dfs(i);
  }
}

