#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int A[100001];
string S;
int N;

// j => 0: Not yet done, 1: Doing, 2: Done
// k => 0: 0 is needed, 1: 1 is needed
int dp[100001][4][2];

int solve(int i, int j, int k) {
  if(i > N) return 0;
  if(dp[i][j][k] != -1) return dp[i][j][k];

  int ans = 0;
  if(j == 0) {
    if(A[i] == j) {
      ans = max(ans, 1 + solve(i + 1, 0, !j));
      ans = max(ans,  solve(i + 1, 1, j));
    }
    else {
      ans = max(ans, 1 + solve(i + 1, 1, !j));
      ans = max(ans, solve(i + 1, 0, j));
    }
  }
  else if(j == 1) {
    if(A[i] != j) {
      ans = max(ans, 1 + solve(i + 1, 1, !j));
      ans = max(ans, solve(i + 1, 2, j));
    }
    else {
      ans = max(ans, solve(i + 1, 1, j));
      ans = 1 + max(ans, solve(i + 1, 2, !j));
    }
  }
  else {
    if(A[i] == j) {
      ans = max(ans, 1 + solve(i + 1, 2, !j));
    }
    else {
      ans = max(ans, solve(i + 1, 2, j));
    }
  }

  return dp[i][j][k] = ans;
}

int main() {
  ios::sync_with_stdio(false);
  memset(dp, -1, sizeof dp);

  cin >> N;
  cin >> S;

  for(int i = 1; i <= N; i++) A[i] = S[i - 1] - '0';

  cout << max(solve(1, 0, 0), solve(1, 0, 1)) << endl;
}
