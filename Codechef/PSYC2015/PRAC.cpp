// Dhoni and Practice Sessions

#include <stdio.h>
#include <math.h>

int main() {
  int T; scanf("%d", &T);

  while(T--){
    double A, B, C; scanf("%lf %lf %lf", &A, &B, &C);
    double numer = A * B * C;
    double sq_denom = (A + B + C) * (B + C - A) * (C + A - B) * (A + B - C);
    double denom = sqrt(sq_denom);
    double ans = numer/denom;
    printf("%.2lf\n", ans);
  }
}
