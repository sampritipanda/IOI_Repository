#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int dp[60001];

int main() {
  dp[0] = 0;
  
  for(int i = 1; i <= 60000; i++) {
    dp[i] = INT_MAX;
    for(int j = 1; j*j <= i; j++) {
      dp[i] = min(dp[i], 1 + dp[i - j*j]);
    }
  }
  
  int N; cin >> N;
  cout << dp[N] << endl;
  
  return 0;
}
