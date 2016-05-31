#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[262144 + 10];
int dp[262144 + 10][81];

int main() {
  freopen("262144.in", "r", stdin);
  freopen("262144.out", "w", stdout);

  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  int ans = 0;

  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= 80; j++) {
      dp[i][j] = -1;
    }
  }

  for(int j = 1; j <= 80; j++) {
    for(int i = 0; i < N; i++) {
      if(A[i] == j) {
        dp[i][j] = i;
      }
      else {
        if(dp[i][j - 1] != -1) {
          dp[i][j] = dp[dp[i][j - 1] + 1][j - 1];
        }
      }

      if(dp[i][j] != -1) ans = max(ans, j);
    }
  }

  cout << ans << endl;
}
