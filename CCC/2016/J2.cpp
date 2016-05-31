#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[4][4];

int main() {
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      cin >> A[i][j];
    }
  }

  int row_sum_1 = A[0][0] + A[0][1] + A[0][2] + A[0][3];
  bool pos = true;
  for(int i = 1; i < 4; i++) {
    int row_sum = A[i][0] + A[i][1] + A[i][2] + A[i][3];
    if(row_sum != row_sum_1) pos = false;
  }

  int col_sum_1 = A[0][0] + A[1][0] + A[2][0] + A[3][0];
  for(int i = 1; i < 4; i++) {
    int col_sum = A[0][i] + A[1][i] + A[2][i] + A[3][i];
    if(col_sum != col_sum_1) pos = false;
  }

  if(col_sum_1 != row_sum_1) pos = false;

  if(pos) cout << "magic" << endl;
  else cout << "not magic" << endl;
}
