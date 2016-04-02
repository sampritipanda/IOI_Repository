#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// v, {special?, bridge?}
vector<pair<int, pair<int, int> > > G[300001];
// v, special
vector<pair<int, int> > tree[300001];
// {u, v}, special
vector<pair<pair<int, int>, int>  > bridges;
map<pair<int, int>, bool> is_bridge;
int dfs_num[300001], dfs_low[300001];
int comp[300001]; bool con_spl[300001];
int timer = 0;
int a, b;

void dfs(int i, int p) {
  dfs_num[i] = dfs_low[i] = ++timer;

  for(int j = 0; j < G[i].size(); j++) {
    int v = G[i][j].first;
    if(v == p) continue;

    if(dfs_num[v] == 0) {
      dfs(v, i);

      if(dfs_low[v] > dfs_num[i]) {
        G[i][j].second.second = true;
        bridges.push_back({{i, v}, G[i][j].second.first});
        is_bridge[{i, v}] = true;
        is_bridge[{v, i}] = true;
      }

      dfs_low[i] = min(dfs_low[i], dfs_low[v]);
    }
    else {
      dfs_low[i] = min(dfs_low[i], dfs_num[v]);
    }
  }
}

void decompose(int i, int p, int spl) {
  comp[i] = timer;
  con_spl[comp[i]] |= spl;

  for(int j = 0; j < G[i].size(); j++) {
    int v = G[i][j].first;
    if(v == p) continue;

    if(is_bridge.count({i, v}) > 0) continue;
    if(comp[v]) {
      if(comp[v] == comp[i]) {
        con_spl[comp[i]] |= G[i][j].second.first;
      }
      continue;
    }

    decompose(v, i, spl | G[i][j].second.first);
  }
}

bool find_ans(int i, int p, int spl) {
  spl |= con_spl[i];
  if(comp[b] == i) return spl;

  for(int j = 0; j < tree[i].size(); j++) {
    int u = tree[i][j].first;
    if(u == p) continue;

    if(find_ans(u, i, spl | tree[i][j].second)) return true;
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  while(M--) {
    int x, y, z; cin >> x >> y >> z;
    G[x].push_back({y, {z, 0}});
    G[y].push_back({x, {z, 0}});
  }

  dfs(1, -1);

  timer = 0;
  for(int i = 1; i <= N; i++) {
    if(comp[i] != 0) continue;

    ++timer;
    decompose(i, -1, false);
  }

  for(auto it: bridges) {
    int u = it.first.first, v = it.first.second;

    tree[comp[u]].push_back({comp[v], it.second});
    tree[comp[v]].push_back({comp[u], it.second});
  }

  cin >> a >> b;

  cout << (find_ans(comp[a], 0, 0) ? "YES" : "NO") << endl;
}
