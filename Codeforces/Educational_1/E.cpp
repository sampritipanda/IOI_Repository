#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1000000007LL

long long dp[31][31][51];

long long solve(int N, int M, int K) {
  if(N * M == K || K == 0) return 0;
  if(N * M < K) return INF;
  if(dp[N][M][K] != -1) return dp[N][M][K];

  long long ans = INF;

  // Vertical Cuts
  for(int i = 1; i <= M - 1; i++) {
    for(int j = 0; j <= K; j++) {
      ans = min(ans, N*N + solve(N, i, j) + solve(N, M - i, K - j));
    }
  }

  // Horizontal Cuts
  for(int i = 1; i <= N - 1; i++) {
    for(int j = 0; j <= K; j++) {
      ans = min(ans, M*M + solve(i, M, j) + solve(N - i, M, K - j));
    }
  }

  return dp[N][M][K] = ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  for(int i = 0; i <= 30; i++) {
    for(int j = 0; j <= 30; j++) {
      for(int k = 0; k <= 50; k++) {
        dp[i][j][k] = -1;
      }
    }
  }

  int T; cin >> T;

  while(T--) {
    int N, M, K; cin >> N >> M >> K;
    cout << solve(N, M, K) << endl;
  }
}
