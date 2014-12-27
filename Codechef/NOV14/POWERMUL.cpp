// Fombinatorial

#include <stdio.h>
#include <cmath>

typedef unsigned long long BigInt;

BigInt calculate(BigInt N, BigInt r, BigInt M){
  double ans = 0;
  for(BigInt i = N; i > r; i--){
    ans += i * log(i);
  }
  for(BigInt i = 1; i <= N - r; i++){
    ans -= i * log(i);
  }

  return ((BigInt) floor(exp(ans))) % M;
}

int main() {
  int T; scanf("%d", &T);
  BigInt N, Q, M, r;

  while(T--){
    scanf("%lld %llu %llu", &N, &M, &Q);
    while(Q--){
      scanf("%llu", &r);
      printf("%llu\n", calculate(N, r, M));
    }
  }
}
