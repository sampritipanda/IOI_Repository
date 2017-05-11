#include <iostream>
#include <algorithm>

using namespace std;

int A[100][100];

int main() {
  int N, K; cin >> N >> K;

  for(int i = 0; i < N; i++) {
    for(int j = i; j < N; j++) {
      if(i == j && K > 0) {
        A[i][j] = 1;
        K--;
      }
      else if(K > 1) {
        A[i][j] = A[j][i] = 1;
        K -= 2;
      }
    }
  }

  if(K > 0) cout << -1 << endl;
  else {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        cout << A[i][j] << " ";
      }
      cout << endl;
    }
  }
}
