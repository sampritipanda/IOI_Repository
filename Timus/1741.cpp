#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N;
vector<vector<pair<int, pair<int, string> > > > G;
long long dp[10001][2];

long long solve(int i, int j) {
  if(i == N) return 0;
  if(dp[i][j] != -1) return dp[i][j];

  long long ans = LLONG_MAX/2;
  for(auto it: G[i]) {
    int y = it.first, d = it.second.first; string type = it.second.second;
    if(type == "Pirated") ans = min(ans, d + solve(y, 1));
    else if(type == "Cracked") ans = min(ans, d + solve(y, j));
    else if(type == "Licensed" && j == 0) ans = min(ans, d + solve(y, j));
  }
  return dp[i][j] = ans;
}

int main() {
  for(int i = 0; i <= 10000; i++) {
    dp[i][0] = dp[i][1] = -1;
  }

  cin >> N;
  G.resize(N + 1);
  int M; cin >> M;

  while(M--) {
    int x, y, d; string s; cin >> x >> y >> d >> s;
    G[x].push_back({y, {d, s}});
  }

  long long ans = solve(1, 0);
  if(ans == LLONG_MAX/2) cout << "Offline" << endl;
  else {
    cout << "Online" << endl;
    cout << ans << endl;
  }
}
