// Task 2

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
  int R, S; scanf("%d %d", &R, &S);
  char grid[R][S];
  vector<vector<int> > apples(R);
  int apple_count = 0;

  for(int i = 0; i < R; i++){
    for(int j = 0; j < S; j++){
      scanf(" %c", &grid[i][j]);
      if(grid[i][j] == 'J'){
        apples[i].push_back(j);
        apple_count++;
      }
    }
  }

  int curr_x = R - 1, curr_y = S - 1;
  char direction = 'R';
  int curr_count = 0;
  int num_steps = 0;
  while(curr_count < apple_count){
    if(apples[curr_x].empty()){
    }
    else {
      curr_count += apples[curr_x].size();
      if(direction == 'L'){
        curr_y = *apples[curr_x].begin();
      }
      else {
      }
    }
  }
}
