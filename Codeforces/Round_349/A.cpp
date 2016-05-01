#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double PI = 3.1415926535;

int main() {
  double d, h, v, e; cin >> d >> h >> v >> e;

  double dec_rate = v/(PI * (d/2) * (d/2));

  if(e - dec_rate >= -0.000001) {
    cout << "NO" << endl;
  }
  else {
    cout << "YES" << endl;
    double dec = dec_rate - e;
    printf("%.8f\n", h/dec);
  }
}
