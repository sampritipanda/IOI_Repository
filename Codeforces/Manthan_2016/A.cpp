#include <iostream>

using namespace std;

int main() {
  int A, B, C; cin >> A >> B >> C;

  bool pos = false;
  for(int i = 0; i <= 10000; i++) {
    for(int j = 0; j <= 10000; j++) {
      if(A * i + B * j == C) {
        pos = true;
      }
    }
  }

  if(pos) cout << "Yes" << endl;
  else cout << "No" << endl;
}
