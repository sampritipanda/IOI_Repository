#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > G;
vector<int> dfs_num, dfs_low;
vector<bool> art;
int timer;
int dfsRoot, rootChild;

void dfs(int i, int p) {
  dfs_num[i] = dfs_low[i] = ++timer;

  for(auto v: G[i]) {
    if(v == p) continue;

    if(dfs_num[v] == -1) {
      if(i == dfsRoot) rootChild++;

      dfs(v, i);

      if(dfs_low[v] >= dfs_num[i]) art[i] = true;
      dfs_low[i] = min(dfs_low[i], dfs_low[v]);
    }
    else {
      dfs_low[i] = min(dfs_low[i], dfs_num[v]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M;
  while(true) {
    cin >> N >> M;
    if(N == 0 && M == 0) break;

    G.clear(); G.resize(N + 1);
    dfs_num.clear(); dfs_low.clear(); art.clear();
    dfs_num.resize(N + 1, -1); dfs_low.resize(N + 1, -1);
    art.resize(N + 1);

    while(M--) {
      int x, y; cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }

    timer = 0;

    for(int i = 1; i <= N; i++) {
      if(dfs_num[i] != -1) continue;

      dfsRoot = i; rootChild = 0;
      dfs(i, 0);

      if(rootChild > 1) art[i] = true;
      else art[i] = false;
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
      if(art[i]) ans++;
    }
    cout << ans << endl;
  }
}
