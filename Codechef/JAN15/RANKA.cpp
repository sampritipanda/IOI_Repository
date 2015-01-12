// Ranka

#include <stdio.h>
#define BOARD_SIZE 9

char board[BOARD_SIZE + 1][BOARD_SIZE + 1];
int num_moves = 0;

void move(int x, int y, char player){
  board[x][y] = player;
  printf("%d %d\n", x, y);
  num_moves++;
}

void pass(){
  printf("0 0\n");
  num_moves++;
}

void delete_color_stage_0(char color){
  for(int i = 1; i <= BOARD_SIZE; i++){
    for(int j = 1; j <= BOARD_SIZE; j++){
      if(board[i][j] == color) board[i][j] = 'X';
    }
  }
}

void delete_color_stage_1(char color){
  for(int j = 1; j <= BOARD_SIZE; j++){
    for(int i = 1; i <= BOARD_SIZE; i++){
      if((i == BOARD_SIZE || i == BOARD_SIZE - 1) && j == 1) continue;
      else if(board[i][j] == color) board[i][j] = 'X';
    }
  }
}

int main() {
  int N; scanf("%d", &N);
  // printf("%d\n", N);

  for(int i = 1; i <= BOARD_SIZE; i++){
    for(int j = 1; j <= BOARD_SIZE; j++){
      board[i][j] = 'X';
    }
  }

  // Stage 0 - Start

  move(BOARD_SIZE, 2, 'B');
  pass();
  move(BOARD_SIZE - 1, 1, 'B');

  int liberty_x = BOARD_SIZE - 1, liberty_y = 2;

  for(int y = 1; y <= BOARD_SIZE; y++){
    for(int x = 1; x <= BOARD_SIZE; x++){
      if(board[x][y] == 'B' || (x == liberty_x && y == liberty_y) || (x == BOARD_SIZE && y == 1)) continue;
      else {
        move(x, y, 'W');
        if(!(x == BOARD_SIZE && y == BOARD_SIZE)) pass();
      }
    }
  }

  move(liberty_x, liberty_y, 'B');
  delete_color_stage_0('W');

  for(int j = 1; j <= BOARD_SIZE; j++){
    for(int i = BOARD_SIZE; i >= 1; i--){
      if(board[i][j] != 'X' || (i == BOARD_SIZE && j == 1)) continue;

      liberty_x = i; liberty_y = j;
      for(int y = 1; y <= BOARD_SIZE; y++){
        for(int x = 1; x <= BOARD_SIZE; x++){
          if(board[x][y] == 'B' || (x == liberty_x && y == liberty_y) || (x == BOARD_SIZE && y == 1)) continue;
          else {
            move(x, y, 'W');
            if(!((x == BOARD_SIZE && y == BOARD_SIZE) || (liberty_y == BOARD_SIZE && y == liberty_y && x == liberty_x - 1))) pass();
          }
        }
      }

      move(liberty_x, liberty_y, 'B');
      delete_color_stage_0('W');

      if(liberty_x == 2 && liberty_y == BOARD_SIZE) break;
    }
  }

  pass();
  move(1, BOARD_SIZE, 'B');
  move(BOARD_SIZE, 1, 'W');
  delete_color_stage_0('B');

  // Stage 0 - End

  // Stage 1 - Start
  move(BOARD_SIZE, 2, 'B');
  pass();
  move(BOARD_SIZE - 1, 2, 'B');
  pass();
  move(BOARD_SIZE - 2, 1, 'B');

  liberty_x = BOARD_SIZE - 2; liberty_y = 2;

  for(int y = 1; y <= BOARD_SIZE; y++){
    for(int x = 1; x <= BOARD_SIZE; x++){
      if(board[x][y] == 'B' || (x == liberty_x && y == liberty_y) || ((x == BOARD_SIZE || x == BOARD_SIZE - 1) && y == 1)) continue;
      else {
        move(x, y, 'W');
        if(!(x == BOARD_SIZE && y == BOARD_SIZE)) pass();
      }
    }
  }

  move(liberty_x, liberty_y, 'B');
  delete_color_stage_1('W');

  for(int j = 1; j <= BOARD_SIZE; j++){
    for(int i = BOARD_SIZE; i >= 1; i--){
      if(board[i][j] != 'X' || ((i == BOARD_SIZE || i == BOARD_SIZE - 1) && j == 1)) continue;

      liberty_x = i; liberty_y = j;
      for(int y = 1; y <= BOARD_SIZE; y++){
        for(int x = 1; x <= BOARD_SIZE; x++){
          if(board[x][y] == 'B' || (x == liberty_x && y == liberty_y) || ((x == BOARD_SIZE || x == BOARD_SIZE - 1) && y == 1)) continue;
          else {
            move(x, y, 'W');
            if(!((x == BOARD_SIZE && y == BOARD_SIZE) || (liberty_y == BOARD_SIZE && y == liberty_y && x == liberty_x - 1))) pass();
          }
        }
      }

      move(liberty_x, liberty_y, 'B');
      delete_color_stage_1('W');

      if(liberty_x == 2 && liberty_y == BOARD_SIZE) break;
    }
  }

  pass();
  move(1, BOARD_SIZE, 'B');
  move(BOARD_SIZE - 1, 1, 'W');
  delete_color_stage_1('B');

  // Stage 1 - End

  // printf("%d\n", num_moves);
}
