#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> G[500001];
bool covered[500001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M, K; cin >> N >> M >> K;

  while(M--) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<int> ans;
  for(int i = 1; i <= N; i++) {
    if(covered[i]) continue;

    covered[i] = true;
    ans.push_back(i);
    for(int _ = 0; _ < G[i].size(); _++) {
      int u = G[i][_];
      covered[u] = true;
      for(int __ = 0; __ < G[u].size(); __++) {
        int v = G[u][__];
        covered[v] = true;
      }
    }
  }

  cout << ans.size() << endl;
  for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
}
