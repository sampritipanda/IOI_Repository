#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[100];
long long dp[100][2];

long long solve(int i, int j) {
  if(i == N) return j;
  if(dp[i][j] != -1) return dp[i][j];

  long long ans = 0;
  if(A[i] == 1) {
    ans += solve(i + 1, 1);
  }
  else {
    ans += solve(i + 1, j);
    if(j == 1) ans += solve(i + 1, 0);
  }

  return dp[i][j] = ans;
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) {
    dp[i][0] = dp[i][1] = -1;
  }

  cout << solve(0, A[0]) << endl;
}
