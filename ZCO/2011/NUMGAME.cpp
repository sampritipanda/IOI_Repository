// Number Game

#include <iostream>
#include <algorithm>

using namespace std;

// dp[i][j][j] = Best Score if Player k starts with the beginning and ending numbers being i and j
int dp[2001][2001][2];   // 0 - Start Me, 1 = Start Friend
int A[2001];

int solve(int i, int j, int player) {
  if(i > j) return 0;

  if(dp[i][j][player] != -1) return dp[i][j][player];

  long long best_ans;
  if(player == 0)
    best_ans = max(A[i] + solve(i + 1, j, 1), A[j] + solve(i, j - 1, 1));
  else
    best_ans = min(solve(i + 1, j, 0), solve(i, j - 1, 0));

  dp[i][j][player] = best_ans;
  return best_ans;
}

int main() {
  int N; cin >> N;

  for(int i = 0; i <= N; i++)
    for(int j = 0; j <= N; j++)
      dp[i][j][0] = dp[i][j][1] = -1;

  for(int i = 1; i <= N; i++)
    cin >> A[i];

  cout << solve(1, N, 0) << endl;
}
