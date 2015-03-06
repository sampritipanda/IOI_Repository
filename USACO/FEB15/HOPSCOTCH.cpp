// Cow Hopscotch

#include <stdio.h>

long long grid[100][100];
long long dp[100][100];

int main() {
  freopen("hopscotch.in", "r", stdin);
  freopen("hopscotch.out", "w", stdout);

  int R, C, K; scanf("%d %d %d", &R, &C, &K);

  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      scanf("%lld", &grid[i][j]);
    }
  }

  for(int i = 0; i < R; i++) dp[i][0] = 0;
  for(int j = 0; j < C; j++) dp[0][j] = 0;
  dp[0][0] = 1;

  for(int i = 1; i < R; i++){
    for(int j = 1; j < C; j++){
      dp[i][j] = 0;
      for(int m = 0; m < i; m++){
        for(int n = 0; n < j; n++){
          if(grid[i][j] != grid[m][n]) {
            dp[i][j] += dp[m][n];
            dp[i][j] %= 1000000007;
          }
        }
      }
    }
  }

  printf("%lld\n", dp[R - 1][C - 1]);

  fclose(stdin);
  fclose(stdout);
}
