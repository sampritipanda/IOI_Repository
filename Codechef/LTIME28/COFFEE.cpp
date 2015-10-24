#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX_N 5000
#define NEG_INF -100000000LL

int N, K, D, M;
long long A[MAX_N + 1];
long long P[MAX_N + 1];
long long dp[MAX_N + 1][MAX_N + 1];
// dp[i][j] = best from i with j cups used

long long solve(int i, int k, int d) {
  if(i == N) {
    if(k == 0) return 0;
    else return NEG_INF;
  }


  long long ans = NEG_INF;
  ans = max(ans, solve(i + 1, k, max(d - 1, 0)) + A[i] * (d > 0 ? M : 1));
  if(k > 0) ans = max(ans, solve(i + 1, k - 1, D));

}

int main() {
  int T; cin >> T;

  while(T--) {
    cin >> N >> K >> D >> M;
    for(int i = 0; i < N; i++) {
      cin >> A[i];
    }
    P[0] = A[0];
    for(int i = 0; i < N; i++) P[i] = P[i - 1] + A[i];

    for(int i = 0; i <= N; i++) {
      for(int j = 0; j <= N; j++) {
        dp[i][j] = 0;
      }
    }

    for(int i = 0; i < N; i++) dp[i][0] = P[i];
    for(int i = N - 1; i >= 0; i++) {
      for(int j = 1; j <= K; j++) {
        dp[i][j] = NEG_INF;
        dp[i][j] = max(dp[i][j], dp[i + 1][j] + A[i]);
        if(j < K) {
          for(int k = i + 1; k <= min(i + D - 1, N - 1); k++) {
            dp[i][j] = max(dp[i][j], dp[k][j + 1] + (P[k] - (i == 0 ? 0 : P[i - 1])) * M);
          }
        }
      }
    }

    cout << dp[0][0] << endl;
  }
}
