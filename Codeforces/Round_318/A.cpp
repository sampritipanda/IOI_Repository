#include <iostream>
#include <algorithm>

using namespace std;

int A[100000];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  for(int i = 0; i < N; i++) {
    while(A[i] % 2 == 0) A[i] /= 2;
    while(A[i] % 3 == 0) A[i] /= 3;
  }

  bool possible = true;
  for(int i = 0; i < N - 1; i++) {
    if(A[i] != A[i + 1]) {
      possible = false;
      break;
    }
  }

  if(possible) cout << "Yes" << endl;
  else cout << "No" << endl;
}
