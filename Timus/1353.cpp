#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[11][82];

int main() {
  memset(dp, 0, sizeof dp);

  int S; cin >> S;

  dp[0][0] = 1;

  for(int i = 1; i <= 9; i++) {
    for(int j = 1; j <= 81; j++) {
      for(int k = 0; k <= 9; k++) {
        if(j - k >= 0) dp[i][j] += dp[i - 1][j - k];
      }
    }
  }

  int ans = 0;
  for(int i = 1; i <= 9; i++) ans += dp[i][S];
  if(S == 1) ans++;
  cout << ans << endl;
}
