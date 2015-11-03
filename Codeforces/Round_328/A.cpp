#include <iostream>
#include <string>

using namespace std;

int main() {
  string board[8];

  for(int i = 0; i < 8; i++) cin >> board[i];

  int black_min = 111, white_min = 111;
  for(int j = 0; j < 8; j++) {
    int black = -1, white = -1;
    for(int i = 0; i < 8; i++) {
      if(board[i][j] == 'B') {
        bool pos = true;
        for(int k = 7; k > i; k--) {
          if(board[k][j] != '.') pos = false;
        }
        if(pos) black = i;
      }
    }
    for(int i = 7; i >= 0; i--) {
      if(board[i][j] == 'W') {
        bool pos = true;
        for(int k = 0; k < i; k++) {
          if(board[k][j] != '.') pos = false;
        }
        if(pos) white = i;
      }
    }

    if(black != -1) black_min = min(black_min, 7 - black);
    if(white != -1) white_min = min(white_min, white);
  }

  if(black_min < white_min) cout << "B" << endl;
  else cout << "A" << endl;
}
