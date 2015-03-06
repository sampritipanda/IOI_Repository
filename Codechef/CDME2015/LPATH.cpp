// Longest Path 

#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int grid[211][211];
int R, C;

int di[8] = { -1, -1, 0, +1, +1, +1, 0, -1 };
int dj[8] = { 0, +1, +1, +1, 0, -1, -1, -1 };

int main() {
  int T; scanf("%d", &T);

  while(T--){
    scanf("%d %d", &R, &C);

    for(int i = 0; i < R; i++){
      for(int j = 0; j < C; j++){
        scanf("%d", &grid[i][j]);
      }
    }

    queue<pair<pair<int, int>, int > > Q;
    for(int i = 0; i < R; i++){
      for(int j = 0; j < C; j++){
        if(grid[i][j] == 0) {
          Q.push({{i, j}, 0});
        }
      }
    }

    int max_val = 0;
    while(!Q.empty()){
      auto curr = Q.front();
      Q.pop();
      int i = curr.first.first, j = curr.first.second, dist = curr.second;

      if(i < 0 || i >= R || j < 0 || j >= C) continue;
      if(grid[i][j] != dist) continue;

      if(dist > max_val) max_val = dist;

      for(int k = 0; k < 8; k++){
        Q.push({{i + di[k], j + dj[k]}, dist + 1});
      }
    }

    printf("%d\n", max_val + 1);
  }
}
