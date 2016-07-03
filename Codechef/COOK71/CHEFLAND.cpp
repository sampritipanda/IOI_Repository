#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> G[100001];
set<int> B[100001];
vector<int> tree[100001];
vector<pair<int, int>  > bridges;
int dfs_num[100001], dfs_low[100001];
int comp[100001];
int timer = 0;
int a, b;

void dfs(int i, int p) {
  dfs_num[i] = dfs_low[i] = ++timer;
  int cnt = 0;

  for(int j = 0; j < G[i].size(); j++) {
    int v = G[i][j];
    if(v == p && cnt == 0) {
      cnt++;
      continue;
    }

    if(dfs_num[v] == 0) {
      dfs(v, i);

      if(dfs_low[v] > dfs_num[i]) {
        B[i].insert(v);
        B[v].insert(i);
        bridges.push_back({i, v});
      }

      dfs_low[i] = min(dfs_low[i], dfs_low[v]);
    }
    else {
      dfs_low[i] = min(dfs_low[i], dfs_num[v]);
    }
  }
}

void decompose(int i, int p) {
  comp[i] = timer;

  for(int j = 0; j < G[i].size(); j++) {
    int v = G[i][j];
    if(v == p) continue;

    if(B[i].count(v) > 0) continue;
    if(comp[v]) {
      continue;
    }

    decompose(v, i);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  while(M--) {
    int x, y; cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  dfs(1, -1);

  timer = 0;
  for(int i = 1; i <= N; i++) {
    if(comp[i] != 0) continue;

    ++timer;
    decompose(i, -1);
  }

  for(auto it: bridges) {
    int u = it.first, v = it.second;

    tree[comp[u]].push_back(comp[v]);
    tree[comp[v]].push_back(comp[u]);
  }

  if(bridges.size() <= 1) {
    cout << "YES" << endl;
  }
  else {
    int cnt_1 = 0, cnt_2 = 0;
    for(int i = 1; i <= timer; i++) {
      if(tree[i].size() == 1) cnt_1++;
      else if(tree[i].size() == 2) cnt_2++;
    }
    if(cnt_1 + cnt_2 == timer && cnt_1 == 2) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
}
