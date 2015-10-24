#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  double a, b; cin >> a >> b;

  if(a < b) {
    cout << -1 << endl;
    return 0;
  }

  double type1 = (a - b)/2, type2 = (a + b)/2;
  double x1 = type1/int(type1/b), x2 = type2/int(type2/b);
  if(type1 == 0) x1 = 1e18;
  if(type2 == 0) x2 = 1e18;
  printf("%.9f\n", min(x1, x2));
}
