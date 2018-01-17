#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

string A, B;
int N, M;
int dp[5001][5001][2];

int solve(int i, int j, int k) {
  if(i == N && j == M) return 0;
  if(dp[i][j][k] != -1) return dp[i][j][k];

  int ans = INT_MAX/2;
  char prv = (k == 0 ? A[i - 1] : B[j - 1]);
  if(i < N) {
    ans = min(ans, (prv != A[i]) + solve(i + 1, j, 0));
  }
  if(j < N) {
    ans = min(ans, (prv != B[j]) + solve(i, j + 1, 1));
  }
  return dp[i][j][k] = ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    cin >> N >> M;
    cin >> A >> B;

    for(int i = 0; i <= N; i++) {
      for(int j = 0; j <= M; j++) {
        dp[i][j][0] = dp[i][j][1] = -1;
      }
    }

    cout << 1 + min(solve(1, 0, 0), solve(0, 1, 1)) << endl;
  }
}
