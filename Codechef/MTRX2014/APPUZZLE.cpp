// Arithmetic Puzzle

#include <stdio.h>

typedef unsigned long long int BigInt;

int main(){
  int T; scanf("%d", &T);
  BigInt x, y, z;

  while(T--){
    scanf("%llu %llu %llu", &x, &y, &z);
    BigInt N = 2*z/(x + y);
    BigInt d = (y - x)/(N - 5);
    BigInt a = x - 2*d;

    printf("%llu\n", N);
    for(int i = a; N--; i += d){
      printf("%llu ", a + (i - 1)*d);
    }
    printf("\n");
  }
}
