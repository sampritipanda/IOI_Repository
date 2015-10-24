// Hamro and circles

#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
  double a, R1, R2; cin >> a >> R1 >> R2;

  double theta1 = 2 * asin(a/(2 * R1));
  double theta2 = 2 * asin(a/(2 * R2));

  double area1 = (R1 * R1)/2 * (theta1 - sin(theta1));
  double area2 = (R2 * R2)/2 * (theta2 - sin(theta2));

  double area = area1 + area2;
  printf("%.10lf\n", area);
}
