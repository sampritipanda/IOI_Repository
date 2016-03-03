#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
  long long a, b, c; cin >> a >> b >> c;

  long long d = b * b - 4 * a * c;
  double root1 = (-b + sqrt(d))/(2 * a);
  double root2 = (-b - sqrt(d))/(2 * a);

  printf("%.6f\n", max(root1, root2));
  printf("%.6f\n", min(root1, root2));
}
