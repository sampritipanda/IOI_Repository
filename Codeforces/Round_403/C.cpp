#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> G[200001];
vector<int> path;
int vis[200001];

void dfs(int i) {
  path.push_back(i);
  vis[i] = true;

  for(int u: G[i]) {
    if(vis[u]) continue;
    dfs(u);
    path.push_back(i);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M, K; cin >> N >> M >> K;

  while(M--) {
    int x, y; cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  dfs(1);

  for(int i = 1; i <= N; i++) vis[i] = false;

  int lim = ceil((2 * N)/double(K));

  for(int i = 0; i < path.size(); i++) {
    if(vis[path[i]]) continue;

    vector<int> ans;
    for(int j = 0; j < lim && (i + j) < path.size(); j++) {
      vis[path[i + j]] = true;
      ans.push_back(path[i + j]);
    }
    cout << ans.size() << " ";
    for(int x: ans) cout << x << " ";
    cout << endl;
    K--;
  }
  while(K--) {
    cout << 1 << " " << 1 << endl;
  }
}
