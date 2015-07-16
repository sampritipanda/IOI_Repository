// Devu and his three Hands

#include <iostream>

#define MOD 1000000007

using namespace std;

inline long long pow(long long base, long long exp){
  base %= MOD;
  long long result = 1;
  while(exp > 0){
    if(exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result;
}

inline long long mul(long long a, long long b){
  a %= MOD;
  b %= MOD;
  return ((a * b) % MOD);
}

long long mul_inv(long long a, long long b)
{
  long long b0 = b, t, q;
  long long x0 = 0, x1 = 1;
  if (b == 1) return 1;
  while (a > 1) {
    q = a / b;
    t = b, b = a % b, a = t;
    t = x0, x0 = x1 - q * x0, x1 = t;
  }
  if (x1 < 0) x1 += b0;
  return x1;
}

long long calc(long long N, long long K){
  long long numerator1 = -2 * (3*pow(N,2) + 3*N + 2);
  while(numerator1 < 0) numerator1 += MOD;
  numerator1 = mul(numerator1, pow(K, N + 1));

  long long numerator2 = 3 * pow(N, 2) - 1;
  numerator2 = mul(numerator2, pow(K, N + 2));

  long long numerator3 = 6 * (N + 1);
  numerator3 = mul(numerator3, pow(K, 2*N + 1));

  long long numerator4 = -6 * N;
  while(numerator4 < 0) numerator4 += MOD;
  numerator4 = mul(numerator4, pow(K, 2*N + 2));

  long long numerator5 = pow(K, 3*N + 2);

  long long numerator6 = 3*pow(N,2) + 6*N + 2;
  numerator6 = mul(numerator6, pow(K, N));

  long long numerator7 = (-2 * K - 2 + MOD) % MOD;

  long long numerator = (numerator1 + numerator2 + numerator3 + numerator4 + numerator5 + numerator6 + numerator7) % MOD;
  numerator = mul(numerator, K);

  long long denominator = mul_inv((K - 1) * (K - 1) * (K - 1), MOD);

  long long ans = mul(numerator, denominator);
  return ans;
}

int main() {
  int T; cin >> T;

  while(T--){
    long long N, K; cin >> N >> K;
    cout << calc(N, K) << endl;
  }
}
