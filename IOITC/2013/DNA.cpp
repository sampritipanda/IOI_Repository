#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, K;
string S;
int A[50000];
// dp[i][j][k][l] = Number of ways to fill i...N when ith character is j and form is k
long long dp[50011][5][15];
long long sum[50011][5][15];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  long long R;
  cin >> N >> K >> R;
  cin >> S;
  for(int i = 0; i < N; i++) {
    if(S[i] == 'A') A[i] = 0;
    else if(S[i] == 'C') A[i] = 1;
    else if(S[i] == 'G') A[i] = 2;
    else if(S[i] == 'T') A[i] = 3;
    else A[i] = -1;
  }

  if(A[N - 1] == -1) dp[N - 1][0][1] = dp[N - 1][1][1] = dp[N - 1][2][1] = dp[N - 1][3][1] = 1;
  else dp[N - 1][A[N - 1]][1] = 1;

  for(int i = N - 2; i >= 0; i--) {
    if(A[i] == -1) {
      for(int j = 0; j < 4; j++) {  // current char
        for(int k = 0; k < 4; k++) { // next char
          for(int l = 1; l <= 10; l++) { // current form
            if(j <= k) dp[i][j][l] += dp[i + 1][k][l];
            else dp[i][j][l + 1] += dp[i + 1][k][l];
          }
        }
      }
    }
    else {
      // current char = A[i]
      for(int k = 0; k < 4; k++) { // next char
        for(int l = 1; l <= 10; l++) { // current form
          if(A[i] <= k) dp[i][A[i]][l] += dp[i + 1][k][l];
          else dp[i][A[i]][l + 1] += dp[i + 1][k][l];
        }
      }
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 4; j++) {
      for(int k = 1; k <= K; k++) {
        sum[i][j][k] = sum[i][j][k - 1] + dp[i][j][k];
      }
    }
  }

  char dna_map[4] = {'A', 'C', 'G', 'T'};
  string ans = S;
  int K_left = K;
  for(int i = 0; i < N; i++) {
    if(A[i] == -1) {
      for(int j = 0; j < 4; j++) {
        int next_form = (i > 0 && j < A[i - 1] ? K_left - 1 : K_left);
        if(R > sum[i][j][next_form]) {
          R -= sum[i][j][next_form];
        }
        else {
          ans[i] = dna_map[j];
          A[i] = j;
          break;
        }
      }
    }
    if(i > 0 && ans[i] < ans[i - 1]) K_left--;
  }
  cout << ans << endl;
}
