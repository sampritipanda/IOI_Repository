#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long dp[44][2];

void find(int N, int K) {
  if(K <= dp[N][0]) {
    cout << 0;
    if(N > 1) find(N - 1, K);
  }
  else {
    cout << 1;
    if(N > 1 && K - dp[N][0] > 0) find(N - 1, K - dp[N][0]);
  }
}

int main() {
  memset(dp, 0, sizeof dp);

  int N; long long K; cin >> N >> K;

  dp[1][0] = dp[1][1] = 1;

  for(int i = 2; i <= N; i++) {
    dp[i][0] += dp[i - 1][0] + dp[i - 1][1];
    dp[i][1] += dp[i - 1][0];
  }

  if(dp[N][0] + dp[N][1] < K) cout << -1 << endl;
  else {
    find(N, K);
    cout << endl;
  }

  return 0;
}
