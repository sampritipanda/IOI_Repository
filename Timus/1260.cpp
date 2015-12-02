#include <iostream>
#include <algorithm>

using namespace std;

long long dp[56];

int main() {
  int N; cin >> N;
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 2;

  for(int i = 4; i <= N; i++) {
    dp[i] = dp[i - 1] + dp[i - 3] + 1;
  }

  cout << dp[N] << endl;
}
