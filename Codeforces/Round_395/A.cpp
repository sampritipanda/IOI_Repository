#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> G[100001];
int C[100001];
int dp[100001]; // dp[i] = color of unicolor in subtree of i (-1 if not unicolor)

void dfs_color(int i, int p) {
  int col = C[i];

  for(int u: G[i]) {
    if(u == p) continue;
    dfs_color(u, i);

    if(dp[u] != col) col = -1;
  }

  dp[i] = col;
}

int find_ans(int i, int p, int curr_col) {
  bool curr_pos = true;
  for(int u: G[i]) {
    if(u == p) continue;
    if(dp[u] == -1) curr_pos = false;
  }
  if(curr_pos) return i;

  if(i != 1 && C[i] != curr_col) return -1;

  map<int, int> M;
  for(int u: G[i]) {
    if(u == p) continue;
    M[dp[u]]++;
  }
  if(i != 1) M[curr_col]++;
  else M[C[i]]++;

  for(int u: G[i]) {
    if(u == p) continue;
    M[dp[u]]--;
    if(M[dp[u]] == 0) M.erase(dp[u]);

    if(i == 1) {
      if(M.size() == 1 && M.count(-1) == 0) {
        int ans = find_ans(u, i, M.begin()->first);
        if(ans != -1) return ans;
      }
    }
    else {
      if(M.size() == 1) {
        int ans = find_ans(u, i, M.begin()->first);
        if(ans != -1) return ans;
      }
    }

    M[dp[u]]++;
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;

  for(int i = 1; i <= N - 1; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  for(int i = 1; i <= N; i++) cin >> C[i];

  dfs_color(1, 0);

  int ans = find_ans(1, 0, -1);
  if(ans == -1) cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    cout << ans << endl;
  }
}
