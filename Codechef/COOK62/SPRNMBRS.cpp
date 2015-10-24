#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    long long L, R; cin >> L >> R;

    long long ans = 0;
    if(L == 1) ans++;
    long long pow1 = 2;
    for(int i = 1; i < 60; i++) {
      if(pow1 > R) break;
      long long pow2 = 1;
      for(int j = 0; j < 38; j++) {
        if(pow2 > R || pow1 * pow2 > R) break;
        if(pow1 * pow2 >= L) ans++;
        pow2 *= 3;
      }
      pow1 *= 2;
    }

    cout << ans << endl;
  }
}
