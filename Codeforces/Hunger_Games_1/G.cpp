// Hamro and Izocup

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

const double PI = 3.1415926535897932384626433832795;

int main() {
  double a, R; cin >> a >> R;

  double h = R - sqrt(R*R - (a*a)/4);
  double theta = 2 * asin(a/(2 * R));
  double area = R * R * acos((R - h)/h) - (R - h) * sqrt(2 * R * h - h * h);
  double area2 = (R * R)/2 * (theta - sin(theta));

  // printf("%.7lf\n", h);
  printf("%.10lf\n", area2);
}
