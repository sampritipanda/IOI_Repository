#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int N, K;
long long dp[1 << 18][19];

long long solve(int i, int j) {
  if(i == (1 << N) - 1) return 1;
  if(j > K) return 0;

  if(dp[i][j] != -1) return dp[i][j];

  dp[i][j] = 0;
  for(int k = 0; k < N; k++) {
    if(i & (1 << k)) continue;

    int ln = i & (1 << (k == 0 ? N - 1 : k - 1));
    int rn = i & (1 << (k == N - 1 ? 0 : k + 1));

    if(ln == 0 && rn == 0) dp[i][j] += solve(i | (1 << k), j + 1);
    else if(ln == 0 || rn == 0) dp[i][j] += solve(i | (1 << k), j);
    else dp[i][j] += solve(i | (1 << k), j - 1);

    dp[i][j] %= MOD;
  }
  return dp[i][j];
}

int main() {
  cin >> N >> K;

  for(int i = 0; i < (1 << N); i++) {
    for(int j = 0; j <= K; j++) {
      dp[i][j] = -1;
    }
  }

  cout << solve(0, 0) << endl;

  while(1) {
    int N, K; cin >> N >> K;
    if(N == -1) break;
    cout << dp[N][K] << endl;
  }
}
