#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> G[100001];
bool vis[100001], vis2[100001];

bool dfs(int i, int p) {
  if(vis2[i]) return true;
  if(vis[i]) return false;

  vis[i] = true;
  vis2[i] = true;

  for(auto u: G[i]) {
    if(u == p) continue;
    if(dfs(u, i)) return true;
  }
  vis2[i] = false;
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  while(M--) {
    int x, y; cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  int ans = 0;
  for(int i = 1; i <= N; i++) {
    if(vis[i]) continue;

    if(!dfs(i, 0)) ans++;
  }
  cout << ans << endl;
}
