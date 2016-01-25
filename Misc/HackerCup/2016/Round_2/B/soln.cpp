#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

int N, K; long double p;
long double dp[3001][3001];
long double dp2[3001];
long double dp_p[3001][3001];

// Probablity of j heads from i flips
long double solve(int i, int j) {
  if(i == 0) {
    if(j == 0) return 1.0;
    else return 0.0;
  }

  if(dp[i][j] >= -0.05) return dp[i][j];

  long double ans = 0.0;
  if(j > 0) ans += p * solve(i - 1, j - 1);
  if(i > j) ans += (1 - p) * solve(i - 1, j);

  return dp[i][j] = ans;
}

long double solve2(int i, int j) {
  if(dp_p[i][j] > -0.05) return dp_p[i][j];

  long double ans = solve(i, j);
  if(j < i) ans += solve2(i, j + 1);

  return dp_p[i][j] = ans;
}

long double solve0(int i) {
  if(i == 0) return 0.0;
  if(dp2[i] > -0.05) return dp2[i];

  long double ans = 0;
  for(int j = K; j <= i; j++) {
    ans = max(ans, solve2(j, K) + solve0(i - j));
  }
  return dp2[i] = ans;
}

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    cin >> N >> K >> p;

    for(int i = 0; i <= 3000; i++) {
      dp2[i] = -2;
      for(int j = 0; j <= 3000; j++) {
        dp[i][j] = -2;
        dp_p[i][j] = -2;
      }
    }

    long double ans = solve0(N);
    // for(int i = K; i <= N; i++) {
    //   long double curr = (N/i - 1) * solve2(i, K);
    //   curr += solve2(i + (N % i), K);
    //   ans = max(ans, curr);
    // }
    printf("Case #%d: %.9Lf\n", t, ans);
  }
}

