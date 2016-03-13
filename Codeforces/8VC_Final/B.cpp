#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long s, x; cin >> s >> x;

  if(s < x) cout << 0 << endl;
  else if((s & 1LL) != (x & 1LL)) cout << 0 << endl;
  else {
    long long A = (s - x) >> 1LL;
    long long B = A + x;

    long long A2 = A + 1, B2 = B - 1;

    int ans = 0;
    if(A > 0 && B > 0) ans += 2;
    if(A2 > 0 && B2 > 0) ans += 2;

    cout << ans << endl;
  }
}
