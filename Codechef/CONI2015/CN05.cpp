// False Fibonacci Series

#include <stdio.h>
#include <math.h>

#define MOD 1000000007

long long modpow(int base, int exp, int modulus) {
  base %= modulus;
  unsigned long long  result = 1;
  while (exp > 0) {
          if (exp & 1) result = (result * base) % modulus;
          base = (base * base) % modulus;
          exp >>= 1;
        }
  return result;
}

int main() {
  unsigned long long* series = new unsigned long long[100000001];

  int T; scanf("%d", &T);
  while(T--){
    int N; scanf("%d", &N);
    long long ans = 0;
    if(N == 0) ans = 2;
    else if(N == 1) ans = 5;
    else {
      N--;
      ans = modpow(3, N, MOD) * 5;
      ans %= MOD;
    }
    printf("%llu\n", ans);
  }
}
