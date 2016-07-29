#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

struct matrix {
  long long dat[2][2];
  matrix() {
    dat[0][0] = dat[0][1] = dat[1][0] = dat[1][1] = 0;
  }

  matrix(long long a, long long b, long long c, long long d) {
    dat[0][0] = a;
    dat[0][1] = b;
    dat[1][0] = c;
    dat[1][1] = d;
  }
};

inline matrix multiply(matrix A, matrix B) {
  matrix C;
  C.dat[0][0] = (A.dat[0][0] * B.dat[0][0] + A.dat[0][1] * B.dat[1][0]) % MOD;
  C.dat[0][1] = (A.dat[0][0] * B.dat[0][1] + A.dat[0][1] * B.dat[1][1]) % MOD;
  C.dat[1][0] = (A.dat[1][0] * B.dat[0][0] + A.dat[1][1] * B.dat[1][0]) % MOD;
  C.dat[1][1] = (A.dat[1][0] * B.dat[0][1] + A.dat[1][1] * B.dat[1][1]) % MOD;
  return C;
}

inline matrix mat_pow(matrix A, long long exp) {
  matrix res = A; exp--;
  while(exp) {
    if(exp & 1) res = multiply(res, A);
    A = multiply(A, A);
    exp >>= 1;
  }
  return res;
}

inline long long modpow(long long base, long long exp) {
  long long res = 1;

  while(exp) {
    if(exp & 1) res = (res * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }

  return res;
}

int main() {
  matrix transition(1, 1, 2, 0);
  long long denom = 2;

  int N; scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    long long x; scanf("%lld", &x);
    transition = mat_pow(transition, x);
    denom = modpow(denom, x);
  }

  matrix base(1, 1, 1, 0);
  transition = multiply(base, transition);
  matrix inverse(0, modpow(2, MOD - 2), 1, MOD - modpow(2, MOD - 2));
  transition = multiply(transition, inverse);

  denom = (denom * modpow(2, MOD - 2)) % MOD;

  printf("%lld/%lld\n", transition.dat[1][1], denom);
}
