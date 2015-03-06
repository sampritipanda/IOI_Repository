// Robot on Moon 

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class RobotOnMoonEasy {
  public:
  string isSafeCommand(vector <string> board, string S) {
    int N = board.size(), M = board[0].size();
    int r_i = -1, r_j = -1;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++){
        if(board[i][j] == 'S') {
          r_i = i, r_j = j;
        }
      }
    }

    bool flag = true;
    for(auto c: S){
      int i = r_i, j = r_j;
      if(c == 'U'){
        i--;
      }
      else if(c == 'D'){
        i++;
      }
      else if(c == 'L'){
        j--;
      }
      else {
        j++;
      }

      if(i < 0 || i >= N || j < 0 || j >= M) {
        flag = false;
        break;
      }
      if(board[i][j] == '#'){
        continue;
      }

      board[i][j] = 'S';
      board[r_i][r_j] = '.';
      r_i = i;
      r_j = j;
    }

    if(flag) return "Alive";
    else return "Dead";
  }
};

