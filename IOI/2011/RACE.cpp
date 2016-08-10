#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <climits>

using namespace std;

vector<pair<int, int> > G[200000];
int N, K;
vector<int> C[200000];
int label[200000];
int sz[200000];
int currComp;
// C_pre[x][y] = list of nodes in centroid subtree of x at a distance of y, {edge count}
map<int, int> C_pre[200000];

void dfs_size(int i, int p) {
  currComp++;
  sz[i] = 1;

  for(auto it: G[i]) {
    int v = it.first;
    if(v == p || label[v] != -1) continue;

    dfs_size(v, i);
    sz[i] += sz[v];
  }
}

int find_centroid(int i, int p) {
  for(auto it: G[i]) {
    int v = it.first;
    if(v == p || label[v] != -1) continue;

    if(sz[v] >= currComp/2) return find_centroid(v, i);
  }
  return i;
}

int centroid_decompose(int i, int j) {
  currComp = 0;
  dfs_size(i, -1);

  int centroid = find_centroid(i, -1);
  label[centroid] = j;

  for(auto it: G[centroid]) {
    int v = it.first;
    if(label[v] != -1) continue;

    int nextRoot = centroid_decompose(v, j + 1);
    C[centroid].push_back(nextRoot);
  }

  return centroid;
}

int ans;
bool vis[200000];

void solve_dfs(int root, int i, int p, int d, int ed) {
  if(K == d) {
    ans = min(ans, ed);
  }
  else if(d < K && C_pre[root].count(K - d)) {
    ans = min(ans, ed + C_pre[root][K - d]);
  }

  for(auto it: G[i]) {
    int u = it.first, d2 = it.second;
    if(u == p || vis[u]) continue;

    solve_dfs(root, u, i, d + d2, ed + 1);
  }
}

void mark_dfs(int root, int i, int p, int d, int ed) {
  if(C_pre[root].count(d) == 0) C_pre[root][d] = ed;
  else C_pre[root][d] = min(C_pre[root][d], ed);

  for(auto it: G[i]) {
    int u = it.first, d2 = it.second;
    if(u == p || vis[u]) continue;

    mark_dfs(root, u, i, d + d2, ed + 1);
  }
}

void solve(int root) {
  vis[root] = true;
  for(auto it: G[root]) {
    int u = it.first, d = it.second;
    if(vis[u]) continue;
    solve_dfs(root, u, root, d, 1);
    mark_dfs(root, u, root, d, 1);
  }

  for(int nextRoot: C[root]) {
    solve(nextRoot);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> K;

  for(int i = 0; i < N - 1; i++) {
    int a, b, d; cin >> a >> b >> d;
    G[a].push_back({b, d});
    G[b].push_back({a, d});
  }

  for(int i = 0; i < N; i++) {
    label[i] = -1;
  }

  int root = centroid_decompose(0, 0);

  ans = INT_MAX/2;
  solve(root);

  if(ans == INT_MAX/2) ans = -1;
  cout << ans << endl;
}
