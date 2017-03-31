// Progress Pie

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    int P, X, Y; cin >> P >> X >> Y;

    double pi = 3.141592;

    bool cond_1 = ((X - 50) * (X - 50) + (Y - 50) * (Y - 50)) <= (50 * 50);
    double ang = (atan2(X - 50, Y - 50) + 2 * pi);
    if(ang > 2 * pi) ang -= 2 * pi;
    bool cond_2 = ang/(2 * pi) <= (P/100.0 + 0.00001);

    cout << "Case #" << t << ": ";
    if (cond_1 && cond_2) cout << "black" << endl;
    else cout << "white" << endl;
  }
}
