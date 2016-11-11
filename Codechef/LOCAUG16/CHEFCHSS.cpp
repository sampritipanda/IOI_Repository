#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int F1, F2, R1, R2, R3, R4; cin >> F1 >> F2 >> R1 >> R2 >> R3 >> R4;

    double p1, p2, p3, p4; cin >> p1 >> p2 >> p3 >> p4;

    double T1 = -F1 + p1 * (p2 * R1 + (1 - p2) * R2);
    double T2 = -F2 + p3 * (R3 + p4 * R4);

    if(abs(T1 - T2) < 0.0001) cout << "BOTH" << endl;
    else if(T1 > T2) cout << "FIRST" << endl;
    else cout << "SECOND" << endl;
  }
}
