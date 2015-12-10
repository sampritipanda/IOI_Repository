#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int T; cin >> T;

  while(T--) {
    long long a, b, m; cin >> a >> b >> m;
    long long x = min(a, b);

    long long s = (m * (m + 1))/2;

    if(s < x) {
      cout << (a + b) - 2*s << endl;
    }
    else {
      cout << max(a, b) - x << endl;
    }
  }
}
