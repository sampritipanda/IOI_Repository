#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007

long long dp[1000001];

int main() {
  int N, M; cin >> N >> M;

  dp[0] = 1;
  long long pow = 1;
  for(int i = 1; i <= N; i++) {
    dp[i] = M * (dp[i - 1] + pow);
    dp[i] %= MOD;

    pow = (pow * (2*M - 1)) % MOD;
  }
  cout << dp[N] << endl;
}

