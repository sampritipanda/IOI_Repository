#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    double H, A; cin >> H >> A;

    if(H * H < 4 * A) cout << -1 << endl;
    else {
      double X = sqrt(H * H + 4 * A);
      double Y = sqrt(H * H - 4 * A);

      double A = (X + Y)/2;
      double B = X - A;

      if(A > B) swap(A, B);

      cout << fixed << setprecision(6) << A << " " << B << " " << H << endl;
    }
  }
}
