#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

// #define in cin
// #define out cout

int dp[5000001][2];

int main() {
  ifstream in("feast.in");
  ofstream out("feast.out");

  int T, A, B; in >> T >> A >> B;

  for(int i = 0; i <= T; i++) {
    dp[i][0] = dp[i][1] = false;
  }

  dp[0][0] = true;

  for(int i = 1; i <= T; i++) {
    if(i >= A) dp[i][0] |= dp[i - A][0];
    if(i >= B) dp[i][0] |= dp[i - B][0];
  }

  for(int i = 1; i <= T; i++) {
    if(2*i <= T) dp[i][1] |= dp[2*i][0];
    if(2*i + 1 <= T) dp[i][1] |= dp[2*i + 1][0];
  }

  for(int i = 1; i <= T; i++) {
    if(i >= A) dp[i][1] |= dp[i - A][1];
    if(i >= B) dp[i][1] |= dp[i - B][1];
  }

  int ans = 0;
  for(int i = 1; i <= T; i++) {
    if(dp[i][0] || dp[i][1]) ans = max(ans, i);
  }

  out << ans << endl;
}
