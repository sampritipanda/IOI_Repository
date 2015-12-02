#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

#define PI 3.14159265358979323846L

int main() {
  long double x0, y0, r0; cin >> x0 >> y0 >> r0;
  long double x1, y1, r1; cin >> x1 >> y1 >> r1;

  long double d = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));

  if(d > r0 + r1) cout << 0 << endl;
  else if(d <= abs(r1 - r0) && r0 >= r1) {
    cout << setprecision(15) << PI * r1 * r1 << endl;
  }
  else if(d <= abs(r1 - r0) && r1 > r0) {
    cout << setprecision(15) << PI * r0 * r0 << endl;
  }
  else {
    long double phi = acos((r0*r0 + d*d - r1*r1)/(2 * r0 * d)) * 2;
    long double theta = acos((r1*r1 + d*d - r0*r0)/(2 * r1 * d)) * 2;
    long double ans1 = 0.5L * theta * r1 * r1 - 0.5L * r1 * r1 * sin(theta);
    long double ans2 = 0.5L * phi * r0 * r0 - 0.5L * r0 * r0 * sin(phi);
    cout << setprecision(15) << ans1 + ans2 << endl;
  }
}
