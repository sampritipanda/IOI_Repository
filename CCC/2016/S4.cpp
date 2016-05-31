#include <iostream>
#include <algorithm>

using namespace std;

int A[401];
int dp[401][401];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];

  for(int i = 1; i <= N; i++) dp[i][i] = A[i];

  for(int len = 2; len <= N; len++) {
    for(int i = 1; i <= N - len + 1; i++) {
      int j = i + len - 1;

      for(int k = i; k < j; k++) {
        if(dp[i][k] && dp[k + 1][j] && dp[i][k] == dp[k + 1][j]) {
          dp[i][j] = dp[i][k] + dp[k + 1][j];
        }
      }

      int sum = 0, sum2 = 0, k2 = j + 1;
      for(int k = i; k < j - 1; k++) {
        sum += A[k];
        while(sum2 < sum) sum2 += A[--k2];

        if(dp[i][k] && dp[k + 1][k2 - 1] && dp[k2][j] && sum == sum2) {
          dp[i][j] = dp[i][k] + dp[k + 1][k2 - 1] + dp[k2][j];
        }
      }
    }
  }

  int ans = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = i; j <= N; j++) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
}
