// Chef and Segment Game

#include <stdio.h>
#include <cmath>

double calculate(double N, unsigned long long int K){
  if(K && (!(K & (K - 1)))){
    return N/(2*K);
  }
  else {
    unsigned long long int next = pow(2, floor(log(K)/log(2)));
    return calculate(N, next) + calculate(N, next) * (K % next) * 2;
  }
}

int main() {
  int T; scanf("%d", &T);
  double X;
  unsigned long long int K;

  while(T--){
    scanf("%lf %llu", &X, &K);
    printf("%lf\n", calculate(X, K));
  }
}
