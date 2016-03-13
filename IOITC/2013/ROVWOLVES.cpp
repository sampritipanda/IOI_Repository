// RoV Wolves

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long find_sq(long long t) {
  long long L = 1, R = 1000000000LL;
  while(L < R) {
    long long mid = (L + R + 1)/2;
    if(mid * mid < t) {
      L = mid;
    }
    else if(mid * mid > t) {
      R = mid - 1;
    }
    else {
      return mid;
    }
  }
  return L;
}

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
      long long sq = find_sq(t);
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

      if(x == 0 && y == 0) { cout << 0 << endl; continue; }

      long long t;

      if(abs(x) > abs(y)) {
        if(x > 0) {
          long long sq = x * 2 - 1;
          long long y_start = -(x - 1);
          t = sq * sq + (y - y_start);
        }
        else if(x < 0) {
          long long sq = -x * 2;
          long long y_start = -x;
          t = sq * sq + abs(y - y_start);
        }
      }
      else if(abs(x) < abs(y)) {
        if(y > 0) {
          long long sq = y * 2 - 1;
          long long x_start = y;
          t = sq * sq + sq + abs(x - x_start);
        }
        else {
          long long sq = -y * 2;
          long long x_start = y;
          t = sq * sq + sq + x - x_start;
        }
      }
      else {
        if(x > 0 && y > 0) {
          long long sq = x * 2 - 1;
          t = sq * sq + sq;
        }
        else if(x > 0 && y < 0) {
          long long sq = x * 2 + 1;
          t = sq * sq - 1;
        }
        else if(x < 0 && y > 0) {
          long long sq = y * 2;
          t = sq * sq;
        }
        else {
          long long sq = -x * 2;
          t = sq * sq + sq;
        }
      }

      cout << t << endl;
    }
  }
}
