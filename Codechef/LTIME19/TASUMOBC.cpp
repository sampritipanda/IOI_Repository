// Sum of Binomial Coefficient

#include <stdio.h>

long long calculate(long long N, long long k) {
  long long result = 1;
  while(N > 0){
    int a = 0, b = 0;
    if(N > 0){
      a = N % 3;
      N /= 3;
    }
    if(k > 0){
      b = k % 3;
      k /= 3;
    }

    if(b == 0) result *= 1;
    else if(a == 0) result *= 0;
    else {
      for(int i = 1; i <= a; i++) result *= i;
      for(int i = 1; i <= b; i++) result /= i;
      for(int i = 1; i <= (a - b); i++) result /= i;
    }
  }

  return result % 3;
}

int main() {
  int T; scanf("%d", &T);

  while(T--){
    long long N; scanf("%lld", &N);
    long long sum = 0;

    for(long long k = 0; k <= N; k++){
      sum = (sum + calculate(N, k)) % 1000000007;
    }

    printf("%lld\n", sum);
  }
}
