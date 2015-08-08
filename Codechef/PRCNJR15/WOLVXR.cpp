#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    if(N == 1) cout << 1 << endl;
    else cout << 0 << endl;
  }
}
