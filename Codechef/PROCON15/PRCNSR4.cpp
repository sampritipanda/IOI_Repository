#include <iostream>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    for(int i = 0; i < N; i++) {
      int A; cin >> A;
      cout << -A << " ";
    }
    cout << endl;
  }
}
