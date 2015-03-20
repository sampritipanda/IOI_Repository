#include <iostream>

using namespace std;

int main() {
  int w, h; cin >> w >> h;
  char grid[h][w];
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> grid[i][j];
    }
  }
  char step1[w][h];
  for(int j = 0; j < w; j++){
    for(int i = (h - 1); i >= 0; i--){
      step1[j][h - i - 1] = grid[i][j];
    }
  }
  char step2[w][h];
  for(int i = 0; i < w; i++){
    for(int j = 0; j < h; j++){
      step2[i][h - j - 1] = step1[i][j];
    }
  }

  char step3[2*w][2*h];
  for(int i = 0; i < 2*w; i++){
    for(int j = 0; j < 2*h; j++){
      step3[i][j] = step2[i/2][j/2];
    }
  }

  for(int i = 0; i < 2*w; i++){
    for(int j = 0; j < 2*h; j++){
      cout << step3[i][j];
    }
    cout << endl;
  }
}
