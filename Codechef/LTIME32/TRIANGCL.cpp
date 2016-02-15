#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define PI 3.14159265358979L

long double dist(int x1, int y1, int x2, int y2) {
  return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main() {
  int subtask; cin >> subtask;

  int T; cin >> T;

  while(T--) {
    int x1, y1; cin >> x1 >> y1;
    int x2, y2; cin >> x2 >> y2;
    int x3, y3; cin >> x3 >> y3;

    long double a = dist(x1, y1, x2, y2);
    long double b = dist(x2, y2, x3, y3);
    long double c = dist(x1, y1, x3, y3);

    vector<long double> sort_arr = {a, b, c}; sort(sort_arr.begin(), sort_arr.end());
    a = sort_arr[0], b = sort_arr[1], c = sort_arr[2];

    // c^2 = a^2 + b^2 - 2ab cos(C)
    // cos(C) = (c^2 - a^2 - b^2)/(-2 * a * b)

    long double C = acos((c - a - b)/(-2 * sqrt(a) * sqrt(b))) * 180.0/PI;

    // a/sin A = c/sin C
    // sin A = sin C * a/c

    long double A = asin(sin(C * PI/180.0) * sqrt(a)/sqrt(c)) * 180.0/PI;

    long double B = 180.0 - (A + C);

    string type1, type2;
    if(a == b || b == c || a == c) {
      type1 = "Isosceles";
    }
    else {
      type1 = "Scalene";
    }

    if(abs(A - 90) < 1e-6 || abs(B - 90) < 1e-6 || abs(C - 90) < 1e-6) {
      type2 = "right";
    }
    else if(A > 90 || B > 90 || C > 90) {
      type2 = "obtuse";
    }
    else {
      type2 = "acute";
    }

    if(subtask == 1) {
      cout << type1 << " triangle" << endl;
    }
    else {
      cout << type1 << " " << type2 << " triangle" << endl;
    }
  }
}

