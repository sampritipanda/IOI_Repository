#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    bool possible = false;
    for(int i = 1; i <= N - 1; i++) {
      double alt = sqrt(double(N)*N - double(i)*i);
      if(alt - floor(alt) <= 0.0000001) {
        possible = true;
        break;
      }
    }

    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
