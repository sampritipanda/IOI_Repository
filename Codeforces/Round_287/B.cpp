// Amr and Pins

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

inline long long sqr(long long a){
  return a*a;
}

int main() {
  long long r, x1, y1, x2, y2; scanf("%lld %lld %lld %lld %lld", &r, &x1, &y1, &x2, &y2);
  double distance = sqrt(sqr(x2 - x1) + sqr(y2 - y1));
  long long ans = (long long)(ceil(distance/(2.0*r)));
  cout << ans << endl;
}
