// Flowers

#include <iostream>
#include <algorithm>

#define MOD 1000000007

using namespace std;

long long dp[100001], P[100001];

int main() {
  int T, K; cin >> T >> K;
  dp[0] = 1;

  for(int i = 1; i <= 100000; i++) {
    dp[i] = dp[i - 1];
    if(i >= K) dp[i] = (dp[i] + dp[i - K]) % MOD;
  }

  P[0] = 0;
  for(int i = 1; i <= 100000; i++) P[i] = (P[i - 1] + dp[i]) % MOD;

  while(T--) {
    int A, B; cin >> A >> B;
    cout << (P[B] - P[A - 1] + MOD) % MOD << endl;
  }
}
