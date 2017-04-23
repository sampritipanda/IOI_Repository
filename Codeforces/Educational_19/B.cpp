#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int A[100000];
int dp[100000][2];

int solve(int i, int j) {
  if(i == N) {
    if(j == 0) return 0;
    else return INT_MIN/2;
  }
  if(dp[i][j] != -1) return dp[i][j];

  int ans = solve(i + 1, j);
  int new_j = (j + (abs(A[i]) % 2)) % 2;
  ans = max(ans, A[i] + solve(i + 1, new_j));
  return dp[i][j] = ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  for(int i = 0; i < N; i++) dp[i][0] = dp[i][1] = -1;

  cout << solve(0, 1) << endl;
}
