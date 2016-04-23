#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

// true = outside, false = inside
// edge needs to be different sides => (u | v) & (!u | !v)

int N;
pair<int, int> edges[200];
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

// return false if j is inside i (or opp) or if j is disjoint from i
bool intersect(int i, int j) {
  int x1 = edges[i].first, y1 = edges[i].second;
  int x2 = edges[j].first, y2 = edges[j].second;

  if(x1 > y1) swap(x1, y1);
  if(x2 > y2) swap(x2, y2);

  if((y1 - x1 + 1) < (y2 - x2 + 1)) {
    swap(x1, x2);
    swap(y1, y2);
  }

  if(x1 <= x2 && y2 <= y1) return false;
  if(y2 <= x1 || x2 >= y1) return false;
  return true;
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

  int M; cin >> N >> M;

  for(int i = 0; i < M; i++) cin >> edges[i].first >> edges[i].second;
  for(int i = 0; i < M; i++) {
    for(int j = i + 1; j < M; j++) {
      if(intersect(i, j)) {
        add(2*i, 2*j);
        add(2*i ^ 1, 2*j ^ 1);
      }
    }
  }

  for(int i = 0; i < 2*M; i++) {
    if(dfs_num[i]) continue;
    dfs(i);
  }

  for(int i = 0; i < 2*M; i++) {
    for(auto u: G[i]) {
      G2[scc[i]].push_back(scc[u]);
    }
  }

  for(int i = 0; i < 2*M; i++) {
    if(vis[i]) continue;
    if(scc[i] != i) continue;
    dfs2(i);
  }
  reverse(topo.begin(), topo.end());

  bool pos = true;
  for(int i = 0; i < M; i++) {
    int ind_1 = find(topo.begin(), topo.end(), scc[2*i]) - topo.begin();
    int ind_2 = find(topo.begin(), topo.end(), scc[2*i ^ 1]) - topo.begin();

    if(scc[2*i] == scc[2*i ^ 1]) {
      pos = false;
      break;
    }

    if(ind_1 < ind_2) {
      ans[i] = true;
    }
    else {
      ans[i] = false;
    }
  }

  if(pos) {
    for(int i = 0; i < M; i++) {
      if(ans[i]) cout << "i";
      else cout << "o";
    }
    cout << endl;
  }
  else {
    cout << "Impossible" << endl;
  }
}
