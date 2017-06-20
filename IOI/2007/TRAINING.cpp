#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cassert>

using namespace std;

int N, M;
vector<int> T[1001];
vector<pair<pair<int, int>, int> > paths;
int depth[1001];
int par[1001][1001], D[1001][1001], lca[1001][1001];
vector<pair<int, pair<int, int> > > cands[1001];
int dp[1001][1 << 10];
int dp_path[5001];

int traverse(int i, int u);
int solve(int i, int mask);

void dfs_root(int i, int p, int d) {
  depth[i] = d;

  for(int u: T[i]) {
    if(u == p) continue;
    dfs_root(u, i, d + 1);
  }
}

void dfs_ind(int i, int p, int dist, pair<int, int> lca_tmp, int src) {
  lca_tmp = min(lca_tmp, {depth[i], i});
  par[src][i] = p;
  D[src][i] = dist;
  lca[src][i] = lca_tmp.second;

  for(int u: T[i]) {
    if(u == p) continue;
    dfs_ind(u, i, dist + 1, lca_tmp, src);
  }
}

// deleted edges from u to top and add up answers for the remaining subtrees
int traverse(int u, int top) {
  if(u == top) return 0;

  int ans = solve(u, 0);
  int prv = u; u = par[1][u];
  while(u != top) {
    int i = find(T[u].begin(), T[u].end(), prv) - T[u].begin();
    ans += solve(u, 1 << i);
    prv = u; u = par[1][u];
  }
  return ans;
}

// Returns the answer for subtree at i with [mask] children allowed
int solve(int i, int mask) {
  mask &= (1 << T[i].size()) - 1;
  if(dp[i][mask] != -1) return dp[i][mask];

  int ans = 0;

  for(int j = 0; j < T[i].size(); j++) {
    int u = T[i][j];
    if(u == par[1][i]) continue;
    if(mask & (1 << j)) continue;

    ans += solve(u, 0);
  }

  for(auto it: cands[i]) {
    int c = it.first, A_i = it.second.first, B_i = it.second.second;
    int A = paths[c].first.first, B = paths[c].first.second, C = paths[c].second;
    if((mask & (1 << A_i)) || (mask & (1 << B_i))) continue;

    if(dp_path[c] == -1) {
      dp_path[c] = C;
      dp_path[c] += traverse(A, i) + traverse(B, i);
    }
    int curr = dp_path[c];
    curr += solve(i, mask | (1 << A_i) | (1 << B_i));
    ans = max(ans, curr);
  }

  return dp[i][mask] = ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> M;

  while(M--) {
    int A, B, C; cin >> A >> B >> C;
    if(C == 0) {
      T[A].push_back(B);
      T[B].push_back(A);
    }
    else {
      paths.push_back({{A, B}, C});
    }
  }

  dfs_root(1, 0, 0);
  for(int i = 1; i <= N; i++) {
    dfs_ind(i, -1, 0, {N + 1, -1}, i);
  }

  int total = 0;

  for(int i = 0; i < paths.size(); i++) {
    int A = paths[i].first.first, B = paths[i].first.second, C = paths[i].second;
    total += C;
    if(D[A][B] % 2 == 1) continue;

    int u = lca[A][B];

    int x = A;
    while(x != u && par[1][x] != u) x = par[1][x];
    int x_i = find(T[u].begin(), T[u].end(), x) - T[u].begin();

    int y = B;
    while(y != u && par[1][y] != u) y = par[1][y];
    int y_i = find(T[u].begin(), T[u].end(), y) - T[u].begin();

    assert(x_i != y_i);
    cands[u].push_back({i, {x_i, y_i}});
  }

  memset(dp, -1, sizeof dp);
  memset(dp_path, -1, sizeof dp_path);

  cout << (total - solve(1, 0)) << endl;
}
