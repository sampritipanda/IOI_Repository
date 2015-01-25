// Not Palindrome

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

long long calc1(long long N, long long M){
}

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int N, M; scanf("%d %d", &N, &M);

  }
}
