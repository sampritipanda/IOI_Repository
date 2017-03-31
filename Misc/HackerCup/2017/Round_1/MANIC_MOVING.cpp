// Manic Moving

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, K;
long long G[101][101];
int S[5001], D[5001];
long long dp[5002][3][101];

// i = current family, j = number of packages in truck, k = current city
long long solve(int i, int j, int k) {
  if(i == K + 1 && j == 0) return 0;
  if(dp[i][j][k] != -1) return dp[i][j][k];

  long long ans = LLONG_MAX/4;
  // deliver package
  if (j > 0) {
    if (D[i - j] == k) {
      ans = min(ans, solve(i, j - 1, k));
    }
    else {
      ans = min(ans, G[k][D[i - j]] + solve(i, j - 1, D[i - j]));
    }
  }
  // take on package
  if (i <= K && j < 2) {
    if (S[i] == k) {
      ans = min(ans, solve(i + 1, j + 1, k));
    }
    else {
      ans = min(ans, G[k][S[i]] + solve(i + 1, j + 1, S[i]));
    }
  }
  return dp[i][j][k] = ans;
}

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        G[i][j] = LLONG_MAX/4;
      }
    }
    for(int i = 1; i <= N; i++) {
      G[i][i] = 0;
    }

    while(M--) {
      int A, B, C; cin >> A >> B >> C;
      G[A][B] = min(G[A][B], (long long)C);
      G[B][A] = min(G[B][A], (long long)C);
    }

    for(int k = 1; k <= N; k++) {
      for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
          G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
        }
      }
    }

    for(int i = 1; i <= K; i++) {
      cin >> S[i] >> D[i];
    }

    for(int i = 0; i <= K + 1; i++) {
      for(int j = 0; j <= 2; j++) {
        for(int k = 0; k <= N; k++) {
          dp[i][j][k] = -1;
        }
      }
    }

    long long ans = solve(1, 0, 1);
    if(ans == LLONG_MAX/4) ans = -1;
    cout << "Case #" << t << ": " << ans << endl;
  }
}
