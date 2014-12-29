// The Kings Army

#include <vector>
#include <string>

using namespace std;

class TheKingsArmyDiv2 {
  public:
  int getNumber(vector <string> state) {
    int R = state.size();
    int C = state[0].size();

    bool flag = false;
    for(int i = 0; i < R; i++){
      for(int j = 0; j < C - 1; j++){
        if(state[i][j] == 'H' && state[i][j + 1] == 'H'){
          flag = true;
          break;
        }
      }
      if(flag) break;
    }

    if(!flag){
        for(int j = 0; j < C; j++){
          for(int i = 0; i < R - 1; i++){
          if(state[i][j] == 'H' && state[i + 1][j] == 'H'){
            flag = true;
            break;
          }
        }
        if(flag) break;
      }
    }

    if(flag) return 0;
    else {
      int count = 0;
      for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
          if(state[i][j] == 'H') count++;
        }
      }

      if(count == 0) return 2;
      else return 1;
    }
  }
};

