#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int d; cin >> d;

    cout << (d % 9) + 1 << endl;
  }
}
