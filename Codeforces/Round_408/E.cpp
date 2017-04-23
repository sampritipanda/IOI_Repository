#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, P, K;
int A[1051], P_A[1051];
int B[1051], P_B[1051];
int C[1051], P_C[1051]; // C[i] = A[i] | B[i];
short dp[1001][1001][51][2]; // dp[i][j][k][prev] = best way to cheat on i..N with j glances remaining and k elements from the previous,
                           // prev = (0 = top continuing, 1 = bottom continuing)

short solve(int i, int j, int k, int prev) {
  if(j < 0) return -10000;
  if(i > N) return 0;
  if(j == 0) return 0;
  if(dp[i][j][k][prev] != -1) return dp[i][j][k][prev];

  dp[i][j][k][prev] = 0;

  // use none
  dp[i][j][k][prev] = max(dp[i][j][k][prev], solve(i + 1, j, max(k - 1, 0), prev));

  // use both together
  if(k == 0) {
    dp[i][j][k][prev] = max((int)dp[i][j][k][prev], (P_C[i + K - 1] - P_C[i - 1]) + solve(i + K, j - 2, 0, 0));
  }

  // use top
  if(k == 0) {
    dp[i][j][k][prev] = max((int)dp[i][j][k][prev], (P_A[i + K - 1] - P_A[i - 1]) + solve(i + 1, j - 1, K - 1, 0));
  }
  else if(k > 0 && prev == 1) {
    int curr_add = 0;
    curr_add += (P_C[i + k - 1] - P_C[i - 1]) - (P_B[i + k - 1] - P_B[i - 1]);
    curr_add += (P_A[i + K - 1] - P_A[i + k - 1]);
    dp[i][j][k][prev] = max((int)dp[i][j][k][prev], curr_add + solve(i + k, j - 1, K - k, 0));
  }

  // use bottom
  if(k == 0) {
    dp[i][j][k][prev] = max((int)dp[i][j][k][prev], (P_B[i + K - 1] - P_B[i - 1]) + solve(i + 1, j - 1, K - 1, 1));
  }
  else if(k > 0 && prev == 0) {
    int curr_add = 0;
    curr_add += (P_C[i + k - 1] - P_C[i - 1]) - (P_A[i + k - 1] - P_A[i - 1]);
    curr_add += (P_B[i + K - 1] - P_B[i + k - 1]);
    dp[i][j][k][prev] = max((int)dp[i][j][k][prev], curr_add + solve(i + k, j - 1, K - k, 1));
  }

  return dp[i][j][k][prev];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> P >> K;

  int R; cin >> R;
  for(int i = 1; i <= R; i++) {
    int x; cin >> x;
    A[x] = 1;
  }
  for(int i = 1; i <= N + K; i++) {
    P_A[i] = P_A[i - 1] + A[i];
  }

  int S; cin >> S;
  for(int i = 1; i <= S; i++) {
    int x; cin >> x;
    B[x] = 1;
  }
  for(int i = 1; i <= N + K; i++) {
    P_B[i] = P_B[i - 1] + B[i];
  }

  for(int i = 1; i <= N + K; i++) {
    C[i] = A[i] | B[i];
    P_C[i] = P_C[i - 1] + C[i];
  }

  if(P > 2 * (N + K - 1)/K) cout << P_C[N] << endl;
  else {
    for(int i = 0; i <= 1000; i++) {
      for(int j = 0; j <= 1000; j++) {
        for(int k = 0; k <= 50; k++) {
          for(int prev = 0; prev < 2; prev++) {
            dp[i][j][k][prev] = -1;
          }
        }
      }
    }

    cout << solve(1, P, 0, 0) << endl;
  }
}
