#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long dp[501][501];
long long A[501], W[501], B[501];

inline long long pref(int i, int j, int k) {
  if(k == 0) {
    return B[j] - B[i - 1];
  }
  else {
    return W[j] - W[i - 1];
  }
}

int main() {
  int N, K; cin >> N >> K;
  for(int i = 1; i <= N; i++) cin >> A[i];

  W[0] = B[0] = 0;
  for(int i = 1; i <= N; i++) {
    W[i] = W[i - 1]; B[i] = B[i - 1];
    if(A[i] == 1) W[i]++;
    else B[i]++;
  }

  for(int i = 1; i <= N; i++) {
    dp[i][K] = pref(i, N, 0) * pref(i, N, 1);
  }

  for(int j = K - 1; j >= 1; j--) {
    for(int i = 1; i <= N; i++) {
      dp[i][j] = INT_MAX;
      for(int k = i; k < N; k++) {
        dp[i][j] = min(dp[i][j], pref(i, k, 0) * pref(i, k, 1) + dp[k + 1][j + 1]);
      }
    }
  }

  cout << dp[1][1] << endl;
}
