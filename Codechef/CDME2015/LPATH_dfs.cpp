// Longest Path

#include <stdio.h>
#include <algorithm>

using namespace std;

int grid[210][210];
int R, C;

int di[8] = { -1, -1, 0, +1, +1, +1, 0, -1 };
int dj[8] = { 0, +1, +1, +1, 0, -1, -1, -1 };

int dfs(int i, int j, int dist){
  if(i < 0 || i >= R || j < 0 || j >= C) return 0;
  if(grid[i][j] != dist) return dist - 1;

  else {
    int curr_max = 0;
    for(int k = 0; k < 8; k++){
      curr_max = max(curr_max, dfs(i + di[k], j + dj[k], dist + 1));
    }

    return curr_max;
  }
}

int main() {
  int T; scanf("%d", &T);

  while(T--){
    scanf("%d %d", &R, &C);

    for(int i = 0; i < R; i++){
      for(int j = 0; j < C; j++){
        scanf("%d", &grid[i][j]);
      }
    }

    int max_val = 0;
    for(int i = 0; i < R; i++){
      for(int j = 0; j < C; j++){
        if(grid[i][j] == 0) max_val = max(max_val, dfs(i, j, 0));
      }
    }

    printf("%d\n", max_val + 1);
  }
}

