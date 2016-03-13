#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007
#define MAX_N 5000

int dp[MAX_N + 1][MAX_N + 1];

int main() {
  for(int j = 1; j <= MAX_N; j++) {
    dp[1][j] = j;
    dp[0][j] = 1;
  }

  for(int i = 2; i <= MAX_N; i++) {
    for(int j = 1; j <= MAX_N; j++) {
      dp[i][j] = 2 * dp[i - 1][j];
      dp[i][j] %= MOD;

      dp[i][j] -= dp[i - 2][j];
      if(dp[i][j] < 0) dp[i][j] += MOD; dp[i][j] %= MOD;

      if(j > 1) dp[i][j] += dp[i][j - 1];
      dp[i][j] %= MOD;
    }
  }

  int Q; scanf("%d", &Q);

  while(Q--) {
    int M, N; scanf("%d %d", &M, &N);

    printf("%d\n", dp[N][M]);
  }
}
