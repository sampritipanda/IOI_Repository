#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

// edge needs to be flipped => (u | v) & (!u | !v)
// edge needs to be orignal => (u | !v) & (!u | v)

vector<int> G[200];
int dfs_num[200], dfs_low[200];
bool on_stack[200];
int scc[200];
stack<int> S;
int timer = 0;

vector<int> G2[200];
vector<int> topo;
bool vis[200];

int ans[200];

void add(int u, int v) {
  // (u | v) === (!u => v) === (!v => u)
  G[u ^ 1].push_back(v);
  G[v ^ 1].push_back(u);
}

void dfs(int i) {
  dfs_num[i] = dfs_low[i] = ++timer;
  S.push(i);
  on_stack[i] = true;

  for(auto u: G[i]) {
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
      if(v == i) break;
    }
  }
}

void dfs2(int i) {
  if(vis[i]) return;
  vis[i] = true;

  for(auto u: G2[i]) {
    dfs2(u);
  }

  topo.push_back(i);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  while(M--) {
    int u, v, c; cin >> u >> v >> c;
    u = (u - 1) * 2; v = (v - 1) * 2;

    if(c == 1) {
      add(u, v ^ 1);
      add(u ^ 1, v);
    }
    else {
      add(u, v);
      add(u ^ 1, v ^ 1);
    }
  }

  for(int i = 0; i < 2*N; i++) {
    if(dfs_num[i]) continue;
    dfs(i);
  }

  for(int i = 0; i < 2*N; i++) {
    for(auto u: G[i]) {
      G2[scc[i]].push_back(scc[u]);
    }
  }

  for(int i = 0; i < 2*N; i++) {
    if(vis[i]) continue;
    if(scc[i] != i) continue;
    dfs2(i);
  }
  reverse(topo.begin(), topo.end());

  bool pos = true;
  int cnt = 0;
  for(int i = 0; i < N; i++) {
    int ind_1 = find(topo.begin(), topo.end(), scc[2*i]) - topo.begin();
    int ind_2 = find(topo.begin(), topo.end(), scc[2*i ^ 1]) - topo.begin();

    if(scc[2*i] == scc[2*i ^ 1]) {
      pos = false;
      break;
    }

    if(ind_1 < ind_2) {
      ans[i] = true;
      cnt++;
    }
    else {
      ans[i] = false;
    }
  }

  if(pos) {
    cout << cnt << endl;
    for(int i = 0; i < N; i++) {
      if(ans[i]) cout << (i + 1) << " ";
    }
    cout << endl;
  }
  else {
    cout << "Impossible" << endl;
  }
}
