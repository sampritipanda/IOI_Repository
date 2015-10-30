// Caesar's Legions

#include <iostream>
#include <algorithm>

#define MOD 100000000

using namespace std;

int N1, N2, K1, K2;
int dp[101][101][2];

int solve(int a, int b, int j) {
  if(a == 0 && b == 0) return 1;
  else if(a == 0) {
    if(j == 0) return 0;
    else {
      if(b > K2) return 0;
      else return 1;
    }
  }
  else if(b == 0) {
    if(j == 1) return 0;
    else {
      if(a > K1) return 0;
      else return 1;
    }
  }
  else {
    if(dp[a][b][j] != -1) return dp[a][b][j];

    int ways = 0;
    if(j == 0) {
      for(int i = 1; i <= min(a, K1); i++) {
        ways += solve(a - i, b, 1);
        ways %= MOD;
      }
    }
    else {
      for(int i = 1; i <= min(b, K2); i++) {
        ways += solve(a, b - i, 0);
        ways %= MOD;
      }
    }

    return dp[a][b][j] = ways;
  }
}

int main() {
  for(int i = 0; i <= 100; i++) {
    for(int j = 0; j <= 100; j++) {
      dp[i][j][0] = dp[i][j][1] = -1;
    }
  }

  cin >> N1 >> N2 >> K1 >> K2;

  cout << (solve(N1, N2, 0) + solve(N1, N2, 1)) % MOD << endl;
}
