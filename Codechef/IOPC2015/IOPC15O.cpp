// Ant Cakewalk

#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int T; scanf("%d", &T);

  while(T--){
    long long l, b, h; scanf("%lld %lld %lld", &l, &b, &h);
    double op=(l+b)*(l+b);
    double op2=(b+h)*(b+h);
    double op3=(l+h)*(l+h);
    double f=sqrt(op+(h*h));
    double g=sqrt(op2+(l*l));
    double h1=sqrt(op3+(b*b));
    printf("%.6lf\n", min(f, min(g, h1)));
  }
}
