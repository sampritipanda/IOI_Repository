#include <bits/stdc++.h>

using namespace std;

#define MOD int(1e9+7)
int N, X, K; 
vector<int> x[101];
long long dp[101][101][101];

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

long long rec(int i, int j, int k) {
  if(j > N-i) return 0;
  if(i == N) return 1;
  if(dp[i][j][k] != -1) return dp[i][j][k];

  long long ans = 0;
  for(int y: x[k]) {
    if(y == X) {
      if(j > 0) {
        ans = (ans + rec(i + 1, j - 1, y)) % MOD;
      }
    }
    else {
      ans = (ans + rec(i + 1, j, y)) % MOD;
    }
  }

  return dp[i][j][k] = ans;
}

int main() {
  scanf("%d %d %d", &N,&X,&K);
  for(int i = 0; i <= 100; i++) {
    for(int j = 0; j <= 100; j++) {
      for(int k = 0; k <= 100; k++) {
        dp[i][j][k] = -1;
      }
    }
  }

  for(int i = 1; i <= 100; i++) {
    x[0].emplace_back(i);
    for(int j = 1; j <= 100; j++) {
      if(gcd(i, j) == 1) x[i].emplace_back(j);
    }
  }

  printf("%lld\n", rec(0, K, 0));
}
