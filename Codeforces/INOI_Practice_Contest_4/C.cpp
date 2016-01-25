#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

double D[2000];
int N; double A, B;
double dp[2000];

double solve(int i) {
  if(i == N) return 0.0;
  if(dp[i] > -1.0) return dp[i];

  double ans = 1e15;
  for(int j = i; j < N; j++) {
    ans = min(ans, A + B*(D[j] - D[i])/2 + solve(j + 1));
  }
  return dp[i] = ans;
}

int main() {
  cin >> N >> A >> B;
  for(int i = 0; i < N; i++) cin >> D[i];
  for(int i = 0; i < N; i++) dp[i] = -1.5;

  sort(D, D + N);

  printf("%.6f\n", solve(0));
}
