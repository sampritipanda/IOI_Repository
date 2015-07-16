// Chef and Submatrix

#include <iostream>
#include <algorithm>

using namespace std;

int A[111][111];
int dp[111][111];

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        cin >> A[i][j];
      }
    }

    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        if(i == 1 && j == 1) dp[i][j] = A[i][j];
        else if(i == 1) dp[i][j] = dp[i][j - 1] ^ A[i][j];
        else if(j == 1) dp[i][j] = dp[i - 1][j] ^ A[i][j];
        else dp[i][j] = dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1] ^ A[i][j];
      }
    }

    int ans = 1;
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        for(int k = 1; k <= N; k++) {
          for(int l = 1; l <= N; l++) {
            ans = max(ans, dp[k][l] ^ dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1]);
          }
        }
      }
    }

    cout << ans << endl;
  }
}
