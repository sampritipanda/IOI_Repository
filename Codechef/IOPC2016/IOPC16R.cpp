#include <iostream>

using namespace std;

int A[9][9];
bool vis[10];

void reset() {
  for(int i = 1; i <= 9; i++) vis[i] = 0;
}

bool check() {
  for(int i = 1; i <= 9; i++) {
    if(!vis[i]) return false;
  }
  return true;
}

bool subcheck(int x, int y) {
  reset();
  for(int i = x; i < x + 3; i++) {
    for(int j = y; j < y + 3; j++) {
      vis[A[i][j]] = true;
    }
  }
  return check();
}

int main() {
  int T; cin >> T;

  while(T--) {
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
        cin >> A[i][j];
      }
    }

    bool pos = true;

    for(int i = 0; i < 9; i++) {
      reset();
      for(int j = 0; j < 9; j++) {
        vis[A[i][j]] = true;
      }
      pos &= check();
    }
    for(int j = 0; j < 9; j++) {
      reset();
      for(int i = 0; i < 9; i++) {
        vis[A[i][j]] = true;
      }
      pos &= check();
    }

    pos &= subcheck(0, 0);
    pos &= subcheck(0, 3);
    pos &= subcheck(0, 6);

    pos &= subcheck(3, 0);
    pos &= subcheck(3, 3);
    pos &= subcheck(3, 6);

    pos &= subcheck(6, 0);
    pos &= subcheck(6, 3);
    pos &= subcheck(6, 6);

    if(pos) cout << "Its A Sudoku" << endl;
    else cout << "Not A Sudoku" << endl;
  }
}
