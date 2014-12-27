// Free ticket

#include <stdio.h>
#include <algorithm>

int main(){
  int C, F; scanf("%d %d", &C, &F);
  int graph[C+1][C+1];
  for(int i = 1; i <= C; i++){
    for(int j = 1; j <= C; j++){
      graph[i][j] = 10000000;
    }
  }

  int x, y, p;
  while(F--){
    scanf("%d %d %d", &x, &y, &p);
    graph[x][y] = p;
    graph[y][x] = p;
  }

  for(int k = 1; k <= C; k++){
    for(int i = 1; i <= C; i++){
      for(int j = 1; j <= C; j++){
        graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }

  int maxCost = 0;
  for(int i = 1; i <= C; i++){
    for(int j = 1; j <= C; j++){
      if(i != j && graph[i][j] > maxCost) maxCost = graph[i][j];
    }
  }

  printf("%d\n", maxCost);
}
