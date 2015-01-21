// Chef and Fibonacci

#include <stdio.h>

int gcd(int a, int b){
  if(b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
  int fib[1000000 + 1];
  fib[0] = 0;
  fib[1] = 1;

  for(int i = 2; i <= 1000000; i++){
    fib[i] = (fib[i - 1] + fib[i - 2]) % 1000000007;
  }

  int T; scanf("%d", &T);

  while(T--){
    int A, B; scanf("%d %d", &A, &B);

    printf("%d\n", fib[gcd(A, B)]);
  }
}
