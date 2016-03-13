#include <iostream>
#include <vector>

using namespace std;

#define MOD 10243

vector<int> G[2505];
long long dp[2505][100];
long long temp_dp[100];
int N, K;

void dfs(int i, int p){
  dp[i][0] = 1;
  dp[i][1] = 1;

  for(auto v: G[i]) {
    if(v == p) continue;

    dfs(v, i);

    for(int j = 0; j <= K; j++) temp_dp[j] = 0;
    for(int j = 2; j <= K; j++) {
      for(int l = 1; l <= j; l++) {   // left subtree size
        int r = j - l;  // right subtree size

        temp_dp[j] += dp[i][l] * dp[v][r];
        temp_dp[j] %= MOD;
      }
    }
    for(int j = 2; j <= K; j++) dp[i][j] = temp_dp[j];
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> K;
  for(int i = 0; i < N - 1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(1, 0);
  long long ans = 0;
  for(int i = 1; i <= N; i++){
    ans += dp[i][K];
    ans %= MOD;
  }
  cout << ans << endl;
}
