#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int A[6001];
int indegree[6001];
vector<set<int> > G;
int dp[6001][2];

int solve(int i, int j) {
  if(dp[i][j] != -1) return dp[i][j];

  int ans = (j == 1 ? A[i] : 0);
  if(j == 1) {
    for(auto v: G[i]) {
      ans += solve(v, 0);
    }
  }
  else {
    for(auto v: G[i]) {
      ans += max(solve(v, 0), solve(v, 1));
    }
  }

  return dp[i][j] = ans;
}

int main() {
  int N; cin >> N;

  for(int i = 1; i <= N; i++) cin >> A[i];

  G.clear();
  G.resize(N + 1);

  for(int i = 0; i <= N; i++) dp[i][0] = dp[i][1] = -1;

  while(true) {
    int x, y; cin >> x >> y;
    if(x == 0 && y == 0) break;

    G[y].insert(x);
  }

  for(int i = 1; i <= N; i++) indegree[i] = 0;
  for(int i = 1; i <= N; i++) {
    for(auto j: G[i]) {
      indegree[j]++;
    }
  }

  int root = -1;
  for(int i = 1; i <= N; i++) {
    if(indegree[i] == 0) {
      root = i;
      break;
    }
  }

  cout << max(solve(root, 0), solve(root, 1)) << endl;
}
