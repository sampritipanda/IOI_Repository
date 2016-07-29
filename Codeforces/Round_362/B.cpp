#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

vector<int> G[100001];;
int P[100001];;
double dp[100001];
int sz[100001];

void dfs(int i) {
  sz[i] = 1;
  for(int u: G[i]) {
    dfs(u);
    sz[i] += sz[u];
  }
}

void solve(int i) {
  dp[i] = dp[P[i]] + 1 + (sz[P[i]] - 1 - sz[i])/2.0;
  for(int u: G[i]) {
    solve(u);
  }
}

int main() {
  int N; cin >> N;

  P[1] = 0;
  for(int i = 2; i <= N; i++) {
    cin >> P[i];
    G[P[i]].push_back(i);
  }

  dfs(1);
  sz[0] = sz[1] + 1;

  dp[0] = 0.0;
  solve(1);

  for(int i = 1; i <= N; i++) cout << fixed << setprecision(8) << dp[i] << " ";
  cout << endl;
}
