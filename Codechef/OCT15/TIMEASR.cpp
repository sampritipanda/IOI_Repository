// Time measure

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int T; cin >> T;

  while(T--) {
    double A; cin >> A;

    for(int i = 0; i <= 11; i++) {
      for(int j = 0; j <= 59; j++) {
        double hour = (i * 60.0 + j)/2.0;
        double minute = j * 6.0;

        double angle = abs(hour - minute);
        angle = min(angle, 360 - angle);

        if(abs(angle - A) < 1/120.0) {
          printf("%02d:%02d\n", i, j);
        }
      }
    }
  }
}
