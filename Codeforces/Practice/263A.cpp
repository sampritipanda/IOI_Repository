// Beautiful Matrix

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int a, b;

  int A[5][5];
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      cin >> A[i][j];
      if(A[i][j] == 1) a = i, b = j;
    }
  }

  cout << abs(a - 2) + abs(b - 2) << endl;
}
