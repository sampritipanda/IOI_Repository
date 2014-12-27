// Tom and Jerry

#include <stdio.h>

unsigned long long modpow(int base, int exp, int modulus) {
  base %= modulus;
  unsigned long long  result = 1;
  while (exp > 0) {
      if (exp & 1) result = (result * base) % modulus;
      base = (base * base) % modulus;
      exp >>= 1;
    }
  return result;
}

int main(){
  int T; scanf("%d", &T);
  int H;

  while(T--){
    scanf("%d", &H);
    printf("%llu\n", modpow(2, H - 1, 1000));
  }
}
