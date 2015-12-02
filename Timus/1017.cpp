#include <iostream>
#include <algorithm>

using namespace std;

long long dp[501][501];

long long solve(int N, int prev) {
  if(N == 0) return 1;
  if(N <= prev) return 0;

  if(dp[N][prev] != -1) return dp[N][prev];

  long long ans = 0;
  for(int i = prev + 1; i <= N; i++) {
    ans += solve(N - i, i);
  }
  return dp[N][prev] = ans;
}

int main() {
  for(int i = 0; i <= 500; i++) {
    for(int j = 0; j <= 500; j++) {
      dp[i][j] = -1;
    }
  }

  int N; cin >> N;

  long long ans = 0;
  for(int i = 1; i < N; i++) {
    ans += solve(N - i, i);
  }
  cout << ans << endl;
}
