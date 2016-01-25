#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N;
int C[2000];
int dp[2000][2000];
int S[2000];

int solve(int i, int j) {
  if(i >= N) return 0;
  if(j <= 0) return 0;

  if(dp[i][j] != -1) return dp[i][j];

  int ans = solve(i, j - 1);
  if(i + (2*j - 1) <= N) ans = max(ans, S[i] - solve(i + (2*j - 1), 2*j - 1));
  if(i + 2*j <= N) ans = max(ans, S[i] - solve(i + 2*j, 2*j));

  return dp[i][j] = ans;
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) cin >> C[i];

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      dp[i][j] = -1;
    }
  }

  S[N - 1] = C[N - 1];
  for(int i = N - 2; i >= 0; i--) S[i] = S[i + 1] + C[i];

  cout << solve(0, 1) << endl;
}
