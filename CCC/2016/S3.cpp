#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

set<int> G[100001];
int A[100001];
int dp[100001];
int N2;

int dfs_clear(int i) {
  int cnt = A[i];
  vector<int> erase;

  for(int u: G[i]) {
    G[u].erase(i);
    int new_cnt = dfs_clear(u);
    if(new_cnt == 0) erase.push_back(u);
    cnt += new_cnt;
  }

  for(int u: erase) {
    G[i].erase(u);
  }

  if(cnt > 0) N2++;
  return cnt;
}

int diameter(int i) {
  if(G[i].size() == 0) {
    dp[i] = 0;
    return 0;
  }

  int ans = 0;
  dp[i] = 0;

  vector<int> temp;
  for(int u: G[i]) {
    ans = max(ans, diameter(u));
    dp[i] = max(dp[i], 1 + dp[u]);
    temp.push_back(1 + dp[u]);
  }

  ans = max(ans, dp[i]);
  sort(temp.begin(), temp.end());
  reverse(temp.begin(), temp.end());
  if(temp.size() > 1) {
    ans = max(ans, temp[0] + temp[1]);
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;

  int root = -1;
  for(int i = 1; i <= M; i++) {
    int x; cin >> x; x++;
    root = x;
    A[x] = 1;
  }

  for(int i = 0; i < N - 1; i++) {
    int a, b; cin >> a >> b; a++; b++;
    G[a].insert(b);
    G[b].insert(a);
  }

  N2 = 0;
  dfs_clear(root);

  cout << 2 * (N2 - 1) - diameter(root) << endl;
}
