#include <iostream>
#include <algorithm>

using namespace std;

int A[100001];
int dp[100001][2];  // dp[i][j] = Ans for (0..i) when ith element is part of increasing/decreasing sequence
                    // j: 0 = increasing, 1 = decreasing

int main() {
  int L, R; cin >> L >> R;
  int N = R - L + 1;

  for(int i = 0; i < N; i++) cin >> A[i];

  dp[0][0] = dp[0][1] = 1;
  for(int i = 1; i < N; i++) {
    if(A[i] >= A[i - 1]) dp[i][0] = dp[i - 1][0];
    else dp[i][0] = 1 + dp[i - 1][0];
    dp[i][0] = min(dp[i][0], 1 + dp[i - 1][1]);

    if(A[i] <= A[i - 1]) dp[i][1] = dp[i - 1][1];
    else dp[i][1] = 1 + dp[i - 1][1];
    dp[i][1] = min(dp[i][1], 1 + dp[i - 1][0]);
  }

  cout << min(dp[N - 1][0], dp[N - 1][1]) << endl;
}
