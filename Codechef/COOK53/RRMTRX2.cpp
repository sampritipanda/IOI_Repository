// Matrix Again

#include <stdio.h>

int main() {
  int N, M; scanf("%d %d", &N, &M);
  int A[N][M];

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      scanf("%d", &A[i][j]);
    }
  }

  long long answer = 1;
  for(int j = 0; j < M; j++){
    long long column_sum = 0;
    for(int i = 0; i < N; i++){
      column_sum += (A[i][j] + 10000007) % 10000007;
    }
    answer = (answer * column_sum) % 10000007;
  }

  printf("%lld\n", answer);
}
