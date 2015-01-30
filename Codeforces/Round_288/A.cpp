// Pasha and Pixels

#include <stdio.h>

int main(){
  int N, M, K; scanf("%d %d %d", &N, &M, &K);
  int grid[1001][1001] = { false };

  bool lost = false;
  for(int k = 1; k <= K; k++){
    int i, j; scanf("%d %d", &i, &j);
    i--; j--;
    grid[i][j] = true;

    if(i == 0 && j == 0){
      if(grid[i + 1][j] && grid[i + 1][j + 1] && grid[i][j + 1]) lost = true;
    }
    else if(i == N - 1 && j == M - 1){
      if(grid[i - 1][j] && grid[i - 1][j - 1] && grid[i][j - 1]) lost = true;
    }
    else if(i == N - 1 && j == 0){
      if(grid[i - 1][j] && grid[i - 1][j + 1] && grid[i][j + 1]) lost = true;
    }
    else if(i == 0 && j == M - 1){
      if(grid[i][j - 1] && grid[i + 1][j - 1] && grid[i + 1][j]) lost = true;
    }
    else if(i == 0){
      if(grid[i + 1][j] && grid[i + 1][j + 1] && grid[i][j + 1]) lost = true;
      else if(grid[i][j - 1] && grid[i + 1][j - 1] && grid[i + 1][j]) lost = true;
    }
    else if(j == 0){
      if(grid[i + 1][j] && grid[i + 1][j + 1] && grid[i][j + 1]) lost = true;
      else if(grid[i - 1][j] && grid[i - 1][j + 1] && grid[i][j + 1]) lost = true;
    }
    else if(i == N - 1){
      if(grid[i - 1][j] && grid[i - 1][j - 1] && grid[i][j - 1]) lost = true;
      else if(grid[i - 1][j] && grid[i - 1][j + 1] && grid[i][j + 1]) lost = true;
    }
    else if(j == M - 1){
      if(grid[i - 1][j] && grid[i - 1][j - 1] && grid[i][j - 1]) lost = true;
      else if(grid[i][j - 1] && grid[i + 1][j - 1] && grid[i + 1][j]) lost = true;
    }
    else {
      if(grid[i + 1][j] && grid[i + 1][j + 1] && grid[i][j + 1]) lost = true;
      else if(grid[i - 1][j] && grid[i - 1][j - 1] && grid[i][j - 1]) lost = true;
      else if(grid[i - 1][j] && grid[i - 1][j + 1] && grid[i][j + 1]) lost = true;
      else if(grid[i][j - 1] && grid[i + 1][j - 1] && grid[i + 1][j]) lost = true;
    }

    if(lost) {
      printf("%d\n", k);
      break;
    }
  }
  if(!lost) printf("0\n");
}
