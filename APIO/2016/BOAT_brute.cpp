#include <iostream>
#include <algorithm>
#include <iomanip>

#define MOD 1000000007

using namespace std;

int A[500], B[500];
int dp[501][10000]; // dp[i][j] = number of ways for i..N if ith school sends j boats

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  for(int j = 1; j <= 100; j++) dp[N][j] = 1;

  for(int i = N - 1; i >= 0; i--) {
    for(int j = A[i]; j <= B[i]; j++) {
      dp[i][j] += dp[i + 1][j + 1];
    }

    for(int j = 100; j >= 1; j--) {
      dp[i][j] += dp[i][j + 1];
    }
    for(int j = 100; j >= 1; j--) {
      dp[i][j] += dp[i + 1][j];
    }
  }

  cout << (dp[0][1] - 1) << endl;

  for(int j = 0; j <= 25; j++) cout << setw(5) << j;
  cout << endl << endl;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= 25; j++) {
      cout << setw(5) << dp[i][j];
    }
    cout << endl;
  }
}
