// Circular Cakewalk

#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int T; scanf("%d", &T);

  while(T--){
    long long r, x, y, x_0, y_0, v; scanf("%lld %lld %lld %lld %lld %lld", &r, &x, &y, &x_0, &y_0, &v);
    double dist = r;
    dist -= sqrt((x_0 - x)*(x_0 - x) + (y_0 - y)*(y_0 - y));
    dist /= v;
    dist = max(dist, 0.0);
    printf("%.6lf\n", dist);
  }
}
