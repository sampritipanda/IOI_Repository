#include <stdio.h>
#include <string.h>
#include <vector>

#define MAX_N 10000000

using namespace std;

bool prime[MAX_N + 1];
int fact[MAX_N + 1];

long long modpow(long long base, long long exp) {
  long long result = 1;

  while(exp > 0) {
    if(exp & 1) result *= base;
    base *= base;
    exp >>= 1;
  }

  return result;
}

int main() {
  prime[0] = prime[1] = false;
  for(int i = 2; i <= MAX_N; i++) prime[i] = true;

  for(int i = 2; i <= MAX_N; i++) {
    if(!prime[i]) continue;

    fact[i] = i;
    for(int j = i + i; j <= MAX_N; j += i) {
      if(prime[j]) fact[j] = i;
      prime[j] = false;
    }
  }

  int T; scanf("%d", &T);

  while(T--) {
    int N; scanf("%d", &N);
    long long ans = 1;
    while(N > 1) {
      long long p = fact[N], cnt = 0;
      while(N % p == 0) N /= p, cnt++;
      if(cnt == 1) ans *= p*p - p + 1;
      else ans *= (modpow(p, 2 * cnt + 1) + 1)/(p + 1);
    }
    printf("%lld\n", ans);
  }
}

