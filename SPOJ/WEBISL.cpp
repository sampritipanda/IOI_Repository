#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int> > G;
vector<int> dfs_num, dfs_low;
vector<vector<int> > scc;
vector<bool> vis;
vector<int> ans;
stack<int> S;
int timer = 0;

void dfs(int i) {
  dfs_num[i] = dfs_low[i] = ++timer;
  S.push(i);
  vis[i] = 1;

  for(auto v: G[i]) {
    if(dfs_num[v] == -1) {
      dfs(v);
    }

    if(vis[v]) {
      dfs_low[i] = min(dfs_low[i], dfs_low[v]);
    }
  }

  if(dfs_num[i] == dfs_low[i]) {
    scc.push_back({});
    while(true) {
      int v = S.top(); S.pop(); vis[v] = false;
      scc.back().push_back(v);
      if(v == i) break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;
  G.resize(N);
  dfs_num.resize(N, -1); dfs_low.resize(N, -1);
  ans.resize(N); vis.resize(N);

  while(M--) {
    int x, y; cin >> x >> y;
    G[x].push_back(y);
  }

  for(int i = 0; i < N; i++) {
    if(dfs_num[i] != -1) continue;

    dfs(i);
  }

  for(int i = 0; i < scc.size(); i++) {
    sort(scc[i].begin(), scc[i].end());
  }

  for(auto it: scc) {
    for(auto it2: it) {
      ans[it2] = it[0];
    }
  }

  for(int i = 0; i < N; i++) cout << ans[i] << endl;
}
