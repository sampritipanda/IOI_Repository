#include <iostream>
#include <algorithm>

using namespace std;

int A[301];
int dp[301]; bool pal[301][301];
int N;

int solve(int i) {
  if(i > N) return 0;
  if(dp[i] != -1) return dp[i];

  int ans = 99999;
  for(int j = i; j <= N; j++) {
    if(pal[i][j]) ans = min(ans, 1 + solve(j + 1));
  }

  return dp[i] = ans;
}

int main() {
  cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      pal[i][j] = false;

  for(int i = 1; i <= N; i++) {
    vector<int> X, Y;
    for(int j = i; j <= N; j++) {
      X.push_back(A[j]); Y = X; reverse(Y.begin(), Y.end());
      if(X == Y) pal[i][j] = true;
    }
  }

  for(int i = 0; i <= N; i++) dp[i] = -1;

  cout << solve(1) << endl;
}
