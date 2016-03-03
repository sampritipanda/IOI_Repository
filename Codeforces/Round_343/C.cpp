#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007

long long dp[2001][2001]; // dp[i][j] = number of >= bracket sequences with length i and balance j

int main() {
  dp[0][0] = 1;

  for(int i = 1; i <= 2000; i++) {
    for(int j = 0; j <= i; j++) {
      if(j < i) dp[i][j] = dp[i - 1][j + 1];
      if(j > 0) dp[i][j] += dp[i - 1][j - 1];

      dp[i][j] %= MOD;
    }
  }

  int A, B; cin >> A >> B;
  int N = A - B;

  int min_diff = 10000; int curr_bal = 0;
  string S; cin >> S;
  for(auto c: S) {
    if(c == '(') curr_bal++;
    else curr_bal--;

    min_diff = min(min_diff, curr_bal);
  }

  if(curr_bal > N || abs(min_diff) > N) {
    cout << 0 << endl;
  }
  else {
    long long ways = 0;

    int start = max(0, -min_diff);
    for(int i = start; i <= N; i++) {  // balance
      for(int j = 0; j <= N; j++) { // length
        int k = N - j;  // suffix length
        int l = -(i + curr_bal); // suffix balance

        if(-l <= 2000) {
          ways += (dp[j][i] * dp[k][-l]) % MOD;
          ways %= MOD;
        }
      }
    }

    cout << ways << endl;
  }
}
