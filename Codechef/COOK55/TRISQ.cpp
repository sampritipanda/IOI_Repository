// Fit Squares in Triangle

#include <iostream>

using namespace std;

int main() {
  int T; cin >> T;
  long long dp[100001];
  dp[1] = dp[2] = dp[3] = 0;

  for(int i = 1; i <= 5000; i++){
    dp[i * 2 + 2] = dp[i * 2 + 3] = (i * (i + 1))/2;
  }

  while(T--){
    int B; cin >> B;
    cout << dp[B] << endl;
  }
}
