#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int C[500002], D[500002];
int dp[500002][2];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, K; cin >> N >> K;

  for(int i = 1; i <= N; i++) {
    cin >> C[i] >> D[i];
    D[i] ^= 1;
  }
  C[N + 1] = K; D[N + 1] = 0;

  for(int i = 1; i <= N; i++) {
    dp[i][0] = D[i]; dp[i][1] = C[i];
    int diff = C[i + 1] - C[i];
    for(int j = 0; j < i; j++) {
      if(C[j] >= diff || dp[j][1] >= diff) break;
      if(dp[j][0] + D[i] > dp[i][0]) {
        dp[i][0] = dp[j][0] + D[i];
        dp[i][1] = C[i] + dp[j][1];
      }
    }
  }

  int ans = 0, ans_2 = 0;
  for(int i = 1; i <= N; i++) {
    if(dp[i][0] > ans) {
      ans = dp[i][0];
      ans_2 = dp[i][1];
    }
  }
  if(ans_2 == 0) ans_2++;

  cout << ans << endl;
  cout << (K - ans_2) << endl;
}

