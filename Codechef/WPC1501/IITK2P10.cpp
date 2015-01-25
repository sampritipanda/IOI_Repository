// Chef and Pattern

#include <stdio.h>

#define MOD 1000000007

long long mod_pow(long long a, long long x, long long p) {
  //calculates a^x mod p in logarithmic time.
  long long res = 1;
  while(x > 0) {
    if( x % 2 != 0) {
      res = (res * a) % p;
    }
    a = (a * a) % p;
    x /= 2;
  }
  return res;
}

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int K, N; scanf("%d %d", &K, &N);
    if(N == 1) printf("1\n");
    else if(N == 2 || N == 3) printf("%d\n", K);
    else {
      long long b_c = mod_pow(2, N - 3, MOD - 1);
      long long a_b_c = mod_pow(K, b_c, MOD);
      printf("%lld\n", a_b_c);
    }
  }
}
