#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
string S;
int A[100000];
int dp[4][4][4][4];
int dp2[4][4][4][4];

int reward(int i, int a, int b, int c) {
  if(a == 3 && b == 3) return 1;
  if(a == 3) {
    if(b == c) return 1;
    return 2;
  }
  if(a == b && b == c) return 1;
  if(a == b || a == c || b == c) return 2;
  return 3;
}

int solve(int i, int l_a, int l_b, int r_a, int r_b) {
  if(i == N) return 0;

  int ans = 0;
  ans = max(ans, reward(i, l_a, l_b, A[i]) + dp[l_b][A[i]][r_a][r_b]);
  ans = max(ans, reward(i, r_a, r_b, A[i]) + dp[l_a][l_b][r_b][A[i]]);
  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N;
  cin >> S;

  for(int i = 0; i < N; i++) {
    if(S[i] == 'M') A[i] = 0;
    else if(S[i] == 'F') A[i] = 1;
    else A[i] = 2;
  }

  for(int i = N - 1; i >= 0; i--) {
    for(int l_a = 0; l_a < 4; l_a++) {
      for(int l_b = 0; l_b < 4; l_b++) {
        for(int r_a = 0; r_a < 4; r_a++) {
          for(int r_b = 0; r_b < 4; r_b++) {
            dp2[l_a][l_b][r_a][r_b] = solve(i, l_a, l_b, r_a, r_b);
          }
        }
      }
    }

    memcpy(dp, dp2, sizeof dp);
  }

  cout << dp[3][3][3][3] << endl;
}

