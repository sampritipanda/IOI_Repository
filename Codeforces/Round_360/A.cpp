#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> G[100001];
int vis[100001];
bool odd_cycle = false;

void dfs(int i, int c) {
  if(vis[i]) {
    if(vis[i] != c) odd_cycle = true;
    return;
  }
  vis[i] = c;

  for(int u: G[i]) {
    int o_c = (c == 1 ? 2 : 1);
    dfs(u, o_c);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  while(M--) {
    int u, v; cin >> u >> v;

    G[u].push_back(v);
    G[v].push_back(u);
  }

  for(int i = 1; i <= N; i++) {
    if(vis[i]) continue;
    dfs(i, 1);
  }

  if(odd_cycle) cout << -1 << endl;
  else {
    int cnt_1 = 0, cnt_2 = 0;
    for(int i = 1; i <= N; i++) {
      if(vis[i] == 1) cnt_1++;
      else cnt_2++;
    }
    cout << cnt_1 << endl;
    for(int i = 1; i <= N; i++) {
      if(vis[i] == 1) cout << i << " ";
    }
    cout << endl;

    cout << cnt_2 << endl;
    for(int i = 1; i <= N; i++) {
      if(vis[i] == 2) cout << i << " ";
    }
    cout << endl;
  }
}

