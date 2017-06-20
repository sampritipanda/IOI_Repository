#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> G[20001];
int sz[20001];

int ans = 20000, ans_id = -1;

void dfs(int i, int p) {
  sz[i] = 1;
  for(int u: G[i]) {
    if(u == p) continue;
    dfs(u, i);
    sz[i] += sz[u];
  }
}

void dfs2(int i, int p, int top) {
  int curr = top;
  for(int u: G[i]) {
    if(u == p) continue;
    curr = max(curr, sz[u]);
    dfs2(u, i, top + sz[i] - sz[u]);
  }
  if(curr < ans || (curr == ans && i < ans_id)) {
    ans = curr;
    ans_id = i;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;

  for(int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dfs(1, 0);
  dfs2(1, 0, 0);
  cout << ans_id << " " << ans << endl;
}
