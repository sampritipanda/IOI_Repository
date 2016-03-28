#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long h1, h2, h; cin >> h1 >> h2;
  int a, b; cin >> a >> b;

  h1 -= 4 * a;

  int ans = -1;
  bool reached = false;
  for(int i = 0; i <= 100000; i++) {
    for(int j = 1; j <= 12; j++) {
      h1 += a;
      if(h1 >= h2) {
        ans = i;
        goto done;
      }
    }

    for(int j = 1; j <= 12; j++) {
      h1 -= b;
    }
  }

done:
  cout << ans << endl;
}
