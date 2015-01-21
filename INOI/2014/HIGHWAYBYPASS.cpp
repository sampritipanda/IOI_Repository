// Highway Bypass

#include <stdio.h>
#include <algorithm>

#define MOD 20011

using namespace std;

int main() {
  int R, C, d; scanf("%d %d %d", &R, &C, &d);

  int grid[R][C];
  long long dp_down[R][C][d + 1], dp_right[R][C][d + 1];
  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      scanf("%d", &grid[i][j]);
      for(int k = 0; k <= d; k++) {
        dp_down[i][j][k] = 0;
        dp_right[i][j][k] = 0;
      }
    }
  }

  dp_down[0][0][0] = 1;
  dp_right[0][0][0] = 1;

  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      if(grid[i][j]){
        for(int k = 1; k <= d; k++){
          if(i == 0 && j == 0){
            dp_down[i][j][k] = 1;
            dp_right[i][j][k] = 1;
          }
          else if(i == 0) dp_right[i][j][k] = dp_right[i][j - 1][k - 1];
          else if(j == 0) dp_down[i][j][k] = dp_down[i - 1][j][k - 1];
          else {
            dp_right[i][j][k] = (dp_right[i][j - 1][k - 1] + dp_down[i][j - 1][d]) % MOD;
            dp_down[i][j][k] = (dp_right[i - 1][j][d] + dp_down[i - 1][j][k - 1]) % MOD;
          }
        }
      }
    }
  }

  long long ans = dp_down[R - 1][C - 1][d] + dp_right[R - 1][C - 1][d];
  ans %= MOD;
  printf("%lld\n", ans);
}
