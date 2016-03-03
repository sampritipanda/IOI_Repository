#include <iostream>

using namespace std;

long long dp[56];

int main() {
  int N; cin >> N;
  dp[0] = 1;
  long long ans = 0;
  for(int i = 1; i <= N; i++) {
    dp[i] = dp[i - 1] * 2;
    ans += dp[i];
  }
  cout << ans << endl;
}
