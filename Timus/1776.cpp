#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

double dp[401][401];

// i = number of fireworks in current segment, j = max number of 10x seconds
double solve(int i, int j) {
  if(j == 0) return 0.0;
  if(j == 1) {
    if(i == 1) return 1.0;
    else return 0.0;
  }
  if(i == 1 && j >= 1) return 1.0;

  if(dp[i][j] > -1) return dp[i][j];

  double ans = 0.0;
  for(int k = 1; k <= i; k++) { // j = chosen firework
    double curr = 1.0;
    int left = k - 1;
    int right = i - k;
    if(left > 0) curr *= solve(left, j - 1);
    if(right > 0) curr *= solve(right, j - 1);

    ans += curr;
  }
  ans /= double(i);

  return dp[i][j] = ans;
}

int main() {
  int N; cin >> N;

  for(int i = 0; i <= 400; i++) {
    for(int j = 0; j <= 400; j++) {
      dp[i][j] = -5;
    }
  }

  double ans = 0;
  for(int i = 1; i <= N; i++) {
    ans += (10 * i * (solve(N - 2, i) - solve(N - 2, i - 1)));
  }

  printf("%.8f\n", ans);
}
