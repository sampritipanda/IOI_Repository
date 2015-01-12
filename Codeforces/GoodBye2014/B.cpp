// New Year Permutation

#include <stdio.h>

int main () {
  int N; scanf("%d", &N);
  int A[N];

  for(int i = 0; i < N; i++) scanf("%d", &A[i]);

  int matrix[N][N];
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      char a; scanf(" %c", &a);
      if(a == '1') matrix[i][j] = 1;
      else matrix[i][j] = 0;
    }
  }

  for (int c = 0 ; c < ( N - 1 ); c++)  {
    for (int d = 0 ; d < N - c - 1; d++) {
      if (A[d] > A[d+1] && matrix[d][d + 1])
      {
        int swap       = A[d];
        A[d]   = A[d+1];
        A[d+1] = swap;
      }
    }
  }

  for(int i = 0; i < N; i++) printf("%d ", A[i]);

  printf("\n");
}
