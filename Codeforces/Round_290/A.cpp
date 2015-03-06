// Fox And Snake

#include <stdio.h>

int main() {
  int N, M; scanf("%d %d", &N, &M);
  char grid[N][M];
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      grid[i][j] = '.';
    }
  }

  for(int i = 0; i < N; i += 2){
    for(int j = 0; j < M; j++){
      grid[i][j] = '#';
    }
  }

  for(int i = 1; i < N; i += 4){
    grid[i][M - 1] = '#';
  }
  if(N > 3){
    for(int i = 3; i < N; i += 4){
      grid[i][0] = '#';
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }
}
