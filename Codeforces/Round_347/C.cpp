#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, char> > G[100001];
vector<int> A, B;
bool pos = true;
int vis[100001];
int N;

void dfs(int i, int c, char edge_c) {
  if(vis[i]) {
    if(vis[i] != c) pos = false;
    return;
  }
  vis[i] = c;
  if(c == 1) A.push_back(i);
  else B.push_back(i);

  for(auto it: G[i]) {
    int v = it.first; char curr_edge_c = it.second;
    if(edge_c == curr_edge_c) {
      dfs(v, c, edge_c);
    }
    else {
      dfs(v, (c == 1 ? 2 : 1), edge_c);
    }
  }
}

vector<int> solve(char color) {
  vector<int> not_pos_vec;
  for(int i = 1; i <= N; i++) not_pos_vec.push_back(i);

  vector<int> ans;

  pos = true;
  memset(vis, 0, sizeof vis);
  for(int i = 1; i <= N; i++) {
    if(vis[i]) continue;

    A.clear(); B.clear();
    dfs(i, 1, color);

    if(!pos) return not_pos_vec;

    if(A.size() <= B.size()) {
      for(auto it: A) ans.push_back(it);
    }
    else {
      for(auto it: B) ans.push_back(it);
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int M; cin >> N >> M;

  while(M--) {
    int u, v; char c; cin >> u >> v >> c;
    G[u].push_back({v, c});
    G[v].push_back({u, c});
  }

  vector<int> B = solve('B'), R = solve('R');
  vector<int> ans = (B.size() <= R.size() ? B : R);

  if(ans.size() == N) cout << -1 << endl;
  else {
    cout << ans.size() << endl;
    for(auto it: ans) cout << it << " ";
    cout << endl;
  }
}
