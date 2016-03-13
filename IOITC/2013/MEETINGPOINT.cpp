#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > G;
vector<int> vis; // {0 = unvisited, 1 = white, 2 = black}
bool bipartite = true;
long long bcnt = 0;
long long wcnt = 0;

void dfs(int i, int c) {
  if(vis[i]) {
    if(vis[i] != c) bipartite = false;
    return;
  }

  vis[i] = c;
  if(c == 1) wcnt++;
  else bcnt++;

  int next_color = (c == 1 ? 2 : 1);
  for(auto u: G[i]) {
    dfs(u, next_color);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;
  G.resize(N);
  vis.resize(N);

  while(M--) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  long long ans = 0;
  for(int i = 0; i < N; i++) {
    if(vis[i]) continue;

    bipartite = true; wcnt = 0; bcnt = 0;
    dfs(i, 1);

    if(bipartite) {
      ans += wcnt * wcnt;
      ans += bcnt * bcnt;
    }
    else {
      long long cnt = wcnt + bcnt;
      ans += cnt * cnt;
    }
  }

  cout << ans << endl;
}
