#include <stdio.h>

using namespace std;

#define MOD_VAL 1000000007

long long fact[10000010];

// Thanks to https://comeoncodeon.wordpress.com/2011/07/31/combination/

/* This function calculates power of p in n! */
long long countFact(long long n, long long p)
{
  long long k=0;
  while (n>=p)
  {
    k+=n/p;
    n/=p;
  }
  return k;
}

/* This function calculates (a^b)%MOD */
long long pow(long long base, long long exp, long long MOD){
  base %= MOD;
  long long result = 1;
  while(exp > 0){
    if(exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result;
}


/*  Modular Multiplicative Inverse
 *      Using Euler's Theorem
 *          a^(phi(m)) = 1 (mod m)
 *              a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(int n, int MOD)
{
  return pow(n,MOD-2,MOD);
}

long long C(int n, int r, int MOD)
{
  if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
    return 0;

  return (fact[n] *
      ((InverseEuler(fact[r], MOD) *
        InverseEuler(fact[n-r], MOD)) % MOD) % MOD);
}

int main() {
  fact[0] = 1;
  for(int i = 1; i <= 10000000; i++) fact[i] = (fact[i - 1] * i) % MOD_VAL;

  int T; scanf("%d", &T);

  while(T--) {
    long long N, K; scanf("%lld %lld", &N, &K);

    long long ans = 0;
    long long ans1 = 1;
    ans1 = (ans1 * (K + N + 1)) % MOD_VAL;
    ans1 = (ans1 * C(K + N, N, MOD_VAL)) % MOD_VAL;

    long long ans2 = N + 1;
    ans2 = (ans2 * C(N + K + 1, K, MOD_VAL)) % MOD_VAL;
    ans2 -= (K * K) % MOD_VAL;
    while(ans2 < 0) ans2 += MOD_VAL;
    ans2 %= MOD_VAL;
    ans2 -= 3*K + 2;
    while(ans2 < 0) ans2 += MOD_VAL;
    ans2 %= MOD_VAL;


    ans = ans1 + ans2;
    while(ans < 0) ans += MOD_VAL;
    ans %= MOD_VAL;
    ans = (ans * N) % MOD_VAL;
    ans = (ans * InverseEuler(((K + 1) * (K + 2)) % MOD_VAL, MOD_VAL)) % MOD_VAL;
    printf("%lld\n", ans);
  }
}
