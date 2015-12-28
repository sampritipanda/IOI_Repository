#include <iostream>
#include <string>
#include <climits>

using namespace std;

int N;
int A[501];

long long dp[501][501];

long long solve(int i, int j) {
  if(i == j) return 1;

  if(dp[i][j] != -1) return dp[i][j];

  if(i == 1 && j == 5) {
    int test = 5;
  }

  long long ans = INT_MAX;
  if(i < N - 1) ans = min(ans, 1 + solve(i + 1, j));
  for(int k = i + 1; k <= j; k++) {
    if(A[i] == A[k]) {
      long long curr = 0;
      if(k - i > 1) curr += solve(i + 1, k - 1);
      else curr += 1;

      if(k < j) curr += solve(k + 1, j);
      ans = min(ans, curr);
    }
  }

  return dp[i][j] = ans;
}

int main() {
  for(int i = 0; i <= 500; i++) {
    for(int j = 0; j <= 500; j++) {
      dp[i][j] = -1;
    }
  }

  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  cout << solve(0, N - 1) << endl;
}
