#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  double d, L, v1, v2; cin >> d >> L >> v1 >> v2;
  double t = (L - d)/(v1 + v2);

  printf("%.6lf\n", t);
}
