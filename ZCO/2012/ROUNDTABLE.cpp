#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[1000001], dp[1000001][2], dp2[1000001][2];

int solve(int i, int j) {
  if(i >= N) return A[N];
  if(dp[i][j] != -1) return dp[i][j];

  if(j == 0) {
    return dp[i][j] = solve(i + 1, 1);
  }
  else {
    return dp[i][j] = A[i] + min(solve(i + 1, 0), solve(i + 1, 1));
  }
}

int solve2(int i, int j) {
  if(i > N) return A[1];
  if(dp2[i][j] != -1) return dp2[i][j];

  if(j == 0) {
    return dp2[i][j] = solve2(i + 1, 1);
  }
  else {
    return dp2[i][j] = A[i] + min(solve2(i + 1, 0), solve2(i + 1, 1));
  }
}

int main() {
  cin >> N;

  for(int i = 0; i <= N; i++) dp[i][0] = dp[i][1] = dp2[i][0] = dp2[i][1] = -1;
  for(int i = 1; i <= N; i++) cin >> A[i];

  if(N == 1) cout << A[1] << endl;
  else cout << min(min(solve(1, 0), solve(1, 1)), min(solve2(2, 0), solve2(2, 1))) << endl;
}
