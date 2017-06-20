#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <bitset>

using namespace std;

vector<int> G[201];
int W[201];
int timer = -1;
int S[201], jmp[201], rev_W[202];
bitset<202> dp[1000001];

void dfs(int i) {
  S[i] = ++timer;
  rev_W[S[i]] = W[i];

  for(int j = 0; j < G[i].size(); j++) {
    dfs(G[i][j]);
  }

  jmp[S[i]] = timer + 1;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, P; cin >> N >> P;

  for(int i = 1; i <= N; i++) {
    int par; cin >> par >> W[i];
    G[par].push_back(i);
  }

  dfs(0);

  int ans = 0;
  dp[0][N + 1] = 1;
  for(int i = 0; i <= P; i++) {
    for(int j = N; j >= 0; j--) {
      dp[i][j] = dp[i][jmp[j]];
      if(i - rev_W[j] >= 0 && dp[i - rev_W[j]][j + 1]) dp[i][j] = 1;
    }
    if(dp[i][0]) ans = i;
  }
  cout << ans << endl;
}
