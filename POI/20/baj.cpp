#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int A[1000000];
int dp[1000000][3];

int solve(int i, int j) {
  if(i == N) return 0;
  if(dp[i][j + 1] != -1) return dp[i][j + 1];

  int ans = INT_MAX/2;
  if(A[i] >= j) ans = min(ans, solve(i + 1, A[i]));
  if(A[i] + j >= j && A[i] + j <= 1 && A[i] + j >= -1) ans = min(ans, 1 + solve(i + 1, A[i] + j));
  if(A[i] + 2 * j >= j && A[i] + 2 * j <= 1 && A[i] + 2 * j >= -1) ans = min(ans, 2 + solve(i + 1, A[i] + 2 * j));

  return dp[i][j + 1] = ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) dp[i][0] = dp[i][1] = dp[i][2] = -1;

  int ans = solve(1, A[0]);
  if(ans == INT_MAX/2) cout << "BRAK" << endl;
  else cout << ans << endl;
}
