// Number of Tilings

#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int main() {
  int N; cin >> N;

  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 5;

  for(int i = 3; i <= N; i++) {
    dp[i] = dp[i - 1] + dp[i - 2] + 2 * dp[i - 3] + 2 * dp[i - 4];
  }

  cout << dp[N] << endl;
}
