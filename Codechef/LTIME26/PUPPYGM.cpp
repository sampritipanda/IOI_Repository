// Puppy and game

#include <iostream>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int A, B; cin >> A >> B;

    if(A % 2 == 1 && B % 2 == 1) {
      cout << "Vanka" << endl;
    }
    else {
      cout << "Tuzik" << endl;
    }
  }
}
