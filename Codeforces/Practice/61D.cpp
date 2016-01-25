#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

vector<pair<int, int> > G[100001];
long long dp[100001][2];

long long solve(int i, int j, int parent) {
  if(dp[i][j] != -1) return dp[i][j];

  if(j == 0) {
    long long sum = 0;
    for(auto v: G[i]) {
      if(v.first != parent) sum += 2 * v.second + solve(v.first, 0, i);
    }
    return dp[i][j] = sum;
  }
  else {
    long long ans = LLONG_MAX;
    long long sum = solve(i, 0, parent);
    for(auto v: G[i]) {
      if(v.first != parent) ans = min(ans, sum - (2 * v.second + solve(v.first, 0, i)) + (v.second + solve(v.first, 1, i)));
    }
    if(ans == LLONG_MAX) ans = 0;
    return dp[i][j] = ans;
  }
}

int main() {
  int N; cin >> N;

  for(int i = 0; i <= N; i++) dp[i][0] = dp[i][1] = -1;

  for(int i = 0; i < N - 1; i++) {
    int x, y, w; cin >> x >> y >> w;
    G[x].push_back({y, w});
    G[y].push_back({x, w});
  }

  cout << solve(1, 1, 0) << endl;
}
