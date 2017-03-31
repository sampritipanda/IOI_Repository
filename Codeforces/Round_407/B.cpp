#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> G[1000001];
int vis[1000001];
vector<pair<int, int> > edges;
int isolated[1000001];

void dfs(int i) {
  if(vis[i]) return;
  vis[i] = 1;

  for(int u: G[i]) {
    dfs(u);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  for(int i = 1; i <= N; i++) isolated[i] = true;

  int self_loop = 0;
  int start = -1;
  while(M--) {
    int u, v; cin >> u >> v;
    edges.push_back({u, v});
    isolated[u] = isolated[v] = false;
    start = u;
    if(u == v) {
      self_loop++;
    }
    else {
      G[u].push_back(v);
      G[v].push_back(u);
    }
  }

  if(M == 1) {
    cout << 0 << endl;
    return 0;
  }

  dfs(start);
  bool pos = true;
  for(int i = 1; i <= N; i++) {
    if(!isolated[i] && !vis[i]) pos = false;
  }

  if(!pos) {
    cout << 0 << endl;
    return 0;
  }

  long long ans = 0;
  for(int i = 1; i <= N; i++) {
    if(G[i].size() > 1) {
      ans += (1LL * G[i].size() * (G[i].size() - 1))/2;
    }
  }

  ans += (1LL * self_loop * (self_loop - 1))/2;
  ans += 1LL * self_loop * edges.size();
  ans -= 1LL * self_loop * self_loop;
  cout << ans << endl;
}
