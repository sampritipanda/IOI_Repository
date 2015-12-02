#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int m1, m2, m3, m4, m5; cin >> m1 >> m2 >> m3 >> m4 >> m5;
  int w1, w2, w3, w4, w5; cin >> w1 >> w2 >> w3 >> w4 >> w5;
  int hs, hu; cin >> hs >> hu;

  double ans = 0;
  ans += max(0.3 * 500, (1 - m1/250.0) * 500 - 50 * w1);
  ans += max(0.3 * 1000, (1 - m2/250.0) * 1000 - 50 * w2);
  ans += max(0.3 * 1500, (1 - m3/250.0) * 1500 - 50 * w3);
  ans += max(0.3 * 2000, (1 - m4/250.0) * 2000 - 50 * w4);
  ans += max(0.3 * 2500, (1 - m5/250.0) * 2500 - 50 * w5);
  ans += 100 * hs;
  ans -= 50 * hu;

  cout << round(ans) << endl;
}
