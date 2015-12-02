#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF int(1e7)

vector<vector<int> > G;
int dp[101][101];
int C[101][101];
int cnt[101], sum[101];

void dfs(int i, int parent) {
  cnt[i] = sum[i] = 0;
  for(auto v: G[i]) {
    if(v == parent) continue;

    dfs(v, i);
    cnt[i] += 1 + cnt[v];
    sum[i] += C[i][v] + sum[v];
  }

  if(parent != -1) G[i].erase(find(G[i].begin(), G[i].end(), parent));
}

int solve(int i, int q) {
  if(q == 0) return 0;
  if(G[i].size() == 0 && q > 0) return INF;
  if(cnt[i] < q) return INF;

  if(dp[i][q] != -1) return dp[i][q];

  vector<int> sort_arr;
  if(cnt[G[i][0]] + 1 <= q) {
    sort_arr.push_back(C[i][G[i][0]] + sum[G[i][0]] + solve(G[i][1], q - (cnt[G[i][0]] + 1)));
  }
  if(cnt[G[i][1]] + 1 <= q) {
    sort_arr.push_back(C[i][G[i][1]] + sum[G[i][1]] + solve(G[i][0], q - (cnt[G[i][1]] + 1)));
  }
  if(cnt[i] == q) {
    sort_arr.push_back(sum[i]);
  }
  for(int j = 0; j <= q; j++) {
    sort_arr.push_back(solve(G[i][0], j) + solve(G[i][1], q - j));
  }
  sort(sort_arr.begin(), sort_arr.end());
  if(sort_arr.size() == 0) return dp[i][q] = INF;
  else return dp[i][q] = sort_arr[0];
}

int main() {
  for(int i = 0; i <= 100; i++) {
    for(int j = 0; j <= 100; j++) {
      dp[i][j] = C[i][j] = -1;
    }
  }

  int N, Q; cin >> N >> Q;
  Q = N - 1 - Q;
  G.resize(N + 1);

  int total = 0;
  for(int i = 0; i < N - 1; i++) {
    int u, v, c; cin >> u >> v >> c;
    total += c;
    G[u].push_back(v);
    G[v].push_back(u);
    C[u][v] = C[v][u] = c;
  }

  dfs(1, -1);

  int remove = solve(1, Q);
  cout << total - remove << endl;
}

