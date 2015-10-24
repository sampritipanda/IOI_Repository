// LCM equation 

#include <stdio.h>
#include <algorithm>

#define MOD 1000000007
#define MAX_N 1000

using namespace std;

int C[1000001], D[1000001];
long long bin[MAX_N + 1][MAX_N + 1];
long long P[MAX_N + 1][MAX_N + 1];

long long modpow(long long base, long long exp) {
  long long result = 1;

  while(exp > 0) {
    if(exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }

  return result;
}

long long gcd(long long a, long long b) {
  if(b == 0) return a;
  else return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
  return (((a * b) % MOD) * modpow(gcd(a, b), MOD - 2)) % MOD;
}

int main() {
  int T; scanf("%d", &T);
  int N, K; scanf("%d %d", &N, &K);
  int A, B, M; scanf("%d %d %d", &A, &B, &M);

  for(int i = 0; i <= M; i++) {
    for(int j = 0; j <= M; j++) {
      if(j == 0 || j == i) bin[i][j] = 1;
      else bin[i][j] = bin[i - 1][j - 1] + bin[i - 1][j];
    }
  }

  for(int n = 1; n <= M; n++) {
    P[n][1] = n;
    for(int k = 2; k <= M; k++) {
      P[n][k] = lcm(P[n][k - 1], (n * bin[n - 1][k - 1]) % MOD);
    }
  }

  for(int i = 2; i <= T; i++) scanf("%d", C + i);
  for(int i = 2; i <= T; i++) scanf("%d", D + i);

  long long ans = 0;

  for(int i = 1; i <= T; i++) {
    if(i >= 2) {
      N = 1 + ((long long)A * ans + C[i]) % M;
      K = 1 + ((long long)B * ans + D[i]) % N;
    }

    ans = P[N][K];
    printf("%lld\n", ans);
  }
}
