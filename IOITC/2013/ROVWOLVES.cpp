// RoV Wolves

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int Q; cin >> Q;

  while(Q--){
    int type; cin >> type;

    if(type == 0){
      long long t; cin >> t;

      if(t == 0) {
        cout << "0 0" << endl;
        continue;
      }
      long long sq = floor(sqrt(double(t)));
      if(sq % 2 == 1) {
        t -= sq*sq;
        long long line = sq + 1;

        if(t < line) {
          long long x = sq/2 + 1;
          long long y = -(sq/2) + t;

          cout << x << " " << y << endl;
        }
        else {
          t -= line; t++;
          long long y = sq/2 + 1;
          long long x = (sq/2 + 1) - t;

          cout << x << " " << y << endl;
        }
      }
      else {
        t -= sq*sq;
        long long line = sq + 1;

        if(t < line) {
          long long x = -(sq/2);
          long long y = (sq/2) - t;

          cout << x << " " << y << endl;
        }
        else {
          t -= line; t++;
          long long y = -(sq/2);
          long long x = -(sq/2) + t;

          cout << x << " " << y << endl;
        }
      }
    }
    else {
      long long x, y; cin >> x >> y;

      if(abs(x) > abs(y)) {
      }
      else if()
    }
  }
}
