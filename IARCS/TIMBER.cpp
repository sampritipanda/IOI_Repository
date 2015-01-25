// The Timber Auction

#include <stdio.h>

int main() {
  int M, N; scanf("%d %d", &M, &N);
  long long sum[M][N];

  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      scanf("%lld", &sum[i][j]);
    }
  }

  for(int i = 1; i < M; i++) sum[i][0] = sum[i - 1][0] + sum[i][0];
  for(int j = 1; j < N; j++) sum[0][j] = sum[0][j - 1] + sum[0][j];

  for(int i = 1; i < M; i++){
    for(int j = 1; j < N; j++){
      sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + sum[i][j] - sum[i - 1][j - 1];
    }
  }

  int C; scanf("%d", &C);
  while(C--){
    int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x1--; y1--; x2--; y2--;

    long long total_sum = sum[x2][y2];
    if(x1 > 0) total_sum -= sum[x1 - 1][y2];
    if(y1 > 0) total_sum -= sum[x2][y1 - 1];
    if(x1 > 0 && y1 > 0) total_sum += sum[x1 - 1][y1 - 1];

    printf("%lld\n", total_sum);
  }
}
