// Pie Progress

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long dp[301][301];  // dp[i][j] = ith day, jth pies with me
vector<int> C[301];
int N, M;

long long solve(int i, int j) {
  if(i == N + 1) return 0;
  if(dp[i][j] != -1) return dp[i][j];

  long long ans = LLONG_MAX/4;
  if(j > 0) ans = min(ans, solve(i + 1, j - 1));
  long long sum = 0;
  for(int k = 1; k <= min(N - j, M); k++) {
    sum += C[i][k];
    ans = min(ans, sum + k * k + solve(i + 1, j + k - 1));
  }
  return dp[i][j] = ans;
}

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
      C[i].clear();
      C[i].resize(M + 1, 0);
      for(int j = 1; j <= M; j++) {
        cin >> C[i][j];
      }
      sort(C[i].begin(), C[i].end());
    }

    for(int i = 0; i <= N; i++) {
      for(int j = 0; j <= N; j++) {
        dp[i][j] = -1;
      }
    }

    cout << "Case #" << t << ": " << solve(1, 0) << endl;
  }
}
