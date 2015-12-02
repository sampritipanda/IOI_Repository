#include <iostream>
#include <algorithm>

using namespace std;

int A[4001];
int dp[4001], best[4001]; bool pal[4001][4001];
int N;

int solve(int i) {
  if(i > N) return 0;
  if(dp[i] != -1) return dp[i];

  int ans = 99999;
  best[i] = -1;
  for(int j = i; j <= N; j++) {
    if(pal[i][j]) {
      int curr = solve(j + 1) + 1;
      if(curr < ans) {
        ans = curr;
        best[i] = j + 1;
      }
    }
  }

  return dp[i] = ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string S; cin >> S;
  N = S.length();

  for(int i = 1; i <= N; i++) A[i] = S[i - 1] - 'a';

  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      pal[i][j] = false;

  for(int i = 1; i <= N; i++) pal[i][i] = true;
  for(int i = 1; i <= N - 1; i++) if(A[i] == A[i + 1]) pal[i][i + 1] = true;
  for(int i = 1; i <= N - 2; i++) if(A[i] == A[i + 2]) pal[i][i + 2] = true;
  for(int l = 4; l <= N; l++) {
    for(int i = 1; i <= N - l + 1; i++) {
      pal[i][i + l - 1] = (A[i] == A[i + l - 1]) && pal[i + 1][i + l - 2];
    }
  }


  for(int i = 0; i <= N; i++) dp[i] = -1;

  int ans = solve(1);
  int i = 1, j = best[i];

  cout << ans << endl;
  while(true) {
    if(i > 1) cout << " ";
    for(; i < j; i++) cout << S[i - 1];
    if(j == N + 1) break;
    j = best[i];
  }
  cout << endl;
}
