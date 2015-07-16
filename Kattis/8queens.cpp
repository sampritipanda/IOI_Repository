// Eight Queens

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  string board[8];
  for(int i = 0; i < 8; i++) cin >> board[i];
  vector<pair<int, int> > queens;

  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if(board[i][j] == '*') queens.push_back({i, j});
    }
  }

  if(queens.size() != 8) cout << "invalid" << endl;
  else {
    bool flag = true;
    for(auto it: queens){
      int count = 0;
      for(int i = 0; i < 8; i++){
        count += (board[i][it.second] == '*');
      }
      if(count != 1) flag = false;

      count = 0;
      for(int j = 0; j < 8; j++){
        count += (board[it.first][j] == '*');
      }
      if(count != 1) flag = false;

      count = 0;
      for(int i = it.first, j = it.second; i >= 0 && j >= 0; i--,j--){
        count += (board[i][j] == '*');
      }
      for(int i = it.first + 1, j = it.second + 1; i < 8 && j < 8; i++,j++){
        count += (board[i][j] == '*');
      }
      if(count != 1) flag = false;

      count = 0;
      for(int i = it.first, j = it.second; i >= 0 && j < 8; i--,j++){
        count += (board[i][j] == '*');
      }
      for(int i = it.first + 1, j = it.second - 1; i < 8 && j >= 0; i++,j--){
        count += (board[i][j] == '*');
      }
      if(count != 1) flag = false;

      if(!flag) {
        break;
      }
    }

    if(flag) cout << "valid" << endl;
    else cout << "invalid" << endl;
  }
}
