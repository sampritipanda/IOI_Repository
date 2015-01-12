// Sereja and LCM

#include <stdio.h>

#define MOD 1000000007

using namespace std;

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

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int N, M, L, R; scanf("%d %d %d %d", &N, &M, &L, &R);

    unsigned long long num_permut = modpow(M, N, MOD), count = 0;

    for(int i = L; i <= R; i++){
      unsigned long long deductions = modpow(M - M/i, N, MOD);
      count = (count + (num_permut - deductions)) % MOD;
    }

    printf("%lld\n", count);
  }
}
