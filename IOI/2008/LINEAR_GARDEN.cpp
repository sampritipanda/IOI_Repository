#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int N, MOD;
string S;
int dp[1000001][3][3];

int solve(int i, int j, int k) {
  if(j > 2 || k > 2) return 0;
  if(i == N) return 1;
  if(dp[i][j][k] != -1) return dp[i][j][k];

  dp[i][j][k] = 0;
  if(j < 2) dp[i][j][k] += solve(i + 1, j + 1, max(k - 1, 0));
  if(k < 2) dp[i][j][k] += solve(i + 1, max(j - 1, 0), k + 1);
  dp[i][j][k] %= MOD;
  return dp[i][j][k];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> MOD >> S;

  memset(dp, -1, sizeof dp);

  int j = 0, k = 0, ans = 1;
  for(int i = 0; i < N; i++) {
    if(S[i] == 'L') {
      j++;
      if(k > 0) k--;
    }
    else {
      ans += solve(i + 1, j + 1, max(k - 1, 0));
      if(j > 0) j--;
      k++;
    }
    ans %= MOD;
  }
  cout << ans << endl;
}
