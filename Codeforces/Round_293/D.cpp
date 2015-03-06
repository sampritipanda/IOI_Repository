// Ilya and Escalator

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

double dp[2001][2001];

int N, T;
double P;

double solve(int n, int t){
  if(t == T) return n - 1;
  if(n > N) return N;
  if(dp[n][t] != 0) return dp[n][t];
  double ans = 0;
  ans += P * solve(n + 1, t + 1);
  ans += (1 - P) * solve(n, t + 1);
  dp[n][t] = ans;
  return ans;
}

int main() {
  cin >> N >> P >> T;

  for(int i = 0; i <= 2000; i++){
    for(int j = 0; j <= 2000; j++){
      dp[i][j] = 0;
    }
  }

  printf("%.7lf\n", solve(1, 0));
}
