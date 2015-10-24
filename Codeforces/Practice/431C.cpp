#include <iostream>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int K, d;
long long dp[101][2];

// i = layer, j = sum left, taken = edge d taken?
long long solve(int j, int taken) {
  if(j == 0) {
    return taken;
  }
  if(j < 0) return 0;

  if(dp[j][taken] != -1) return dp[j][taken];

  long long ans = 0;
  for(int k = 1; k <= K; k++) {
    if(k >= d && !taken) {
      ans += solve(j - k, 1);
    }
    else {
      ans += solve(j - k, taken);
    }

    ans %= MOD;
  }

  return dp[j][taken] = ans;
}

int main() {
  int N; cin >> N >> K >> d;

  for(int i = 0; i <= N; i++) {
    dp[i][0] = dp[i][1] = -1;
  }

  cout << solve(N, 0) << endl;
}
