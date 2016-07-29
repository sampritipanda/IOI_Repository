#include <iostream>
#include <algorithm>

using namespace std;

int A[1000][1000];
int dp[1000][1000];

int main() {
  int N; cin >> N;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }

  for(int i = 0; i < N; i++) dp[i][0] = A[i][0];
  for(int j = 0; j < N; j++) dp[0][j] = A[0][j];

  for(int i = 1; i < N; i++) {
    for(int j = 1; j < N; j++) {
      if(A[i][j] == 0) {
        continue;
      }
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
      if(A[i - dp[i][j]][j - dp[i][j]]) {
        dp[i][j]++;
      }
    }
  }

  int max = 0, cnt = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(dp[i][j] == max) cnt++;
      else if(dp[i][j] > max) {
        max = dp[i][j];
        cnt = 1;
      }
    }
  }
  cout << max * cnt << endl;
}
