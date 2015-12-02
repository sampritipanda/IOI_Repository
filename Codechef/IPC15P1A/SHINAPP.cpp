#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define MOD 1000000007

int dp[100001][301];
long long factorial[301];

int main() {
  for(int i = 1; i <= 100000; i++) dp[i][1] = 1;
  factorial[0] = 1;
  for(int i = 1; i <= 300; i++) factorial[i] = (factorial[i - 1] * i) % MOD;

  for(int j = 2; j <= 300; j++) {
    for(int i = 1; i <= 100000; i++) {
      if(i < j) dp[i][j] = 0;
      else dp[i][j] = (dp[i - 1][j - 1] + dp[i - j][j]) % MOD;
    }
  }

  int T; scanf("%d", &T);

  while(T--) {
    int N, M; scanf("%d %d", &N, &M);
    int x = M - (N * (N + 1))/2;

    long long ans;
    if(x < 0) ans = 0;
    else if(x == 0) ans = 1;
    else ans = dp[x][N];

    ans = (ans * factorial[N]) % MOD;
    printf("%lld\n", ans);
  }
}

