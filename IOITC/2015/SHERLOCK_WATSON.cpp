#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int B[100001];
// dp[i][0] = previous min
// dp[i][1] = previous max
int dp[100001][2];
int N;

int solve(int i, int j) {
  if(i == N + 1) return 0;
  if(dp[i][j] != -1) return dp[i][j];

  int add_0;
  if(i == 1) add_0 = 0;
  else {
    add_0 = abs(1 - (j == 0 ? 1 : B[i - 1]));
  }

  int add_1;
  if(i == 1) add_1 = 0;
  else {
    add_1 = abs(B[i] - (j == 0 ? 1 : B[i - 1]));
  }

  return dp[i][j] = max(add_0 + solve(i + 1, 0), add_1 + solve(i + 1, 1));
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    cin >> N;

    for(int i = 1; i <= N; i++) cin >> B[i];
    for(int i = 0; i <= N; i++) dp[i][0] = dp[i][1] = -1;

    cout << solve(1, 0) << endl;
  }
}
