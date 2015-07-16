// Devu and most energetic minion

#include <iostream>
#include <algorithm>

using namespace std;

long long B[20][20];
long long dp[20][20];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> B[i][j];
    }
  }

  dp[0][0] = B[0][0];

  for(int i = 1; i < N; i++) {
    dp[i][0] = dp[i - 1][0] ^ B[i][0];
  }

  for(int j = 1; j < N; j++) {
    dp[0][j] = dp[0][j - 1] ^ B[0][j];
  }

  for(int i = 1; i < N; i++) {
    for(int j = 1; j < N; j++) {
      dp[i][j] = max(dp[i - 1][j] ^ B[i][j], dp[i][j - 1] ^ B[i][j]);
    }
  }

  cout << dp[N - 1][N - 1] << endl;
}
