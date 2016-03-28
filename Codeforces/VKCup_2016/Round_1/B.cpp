#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define MOD 1000000007LL
#define MOD2 1000000009LL

long long A[200001];

inline long long modpow(long long base, long long exp) {
  long long result = 1;
  while(exp > 0) {
    if(exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; long long K; cin >> N >> K;

  for(int i = 0; i <= N; i++) {
    cin >> A[i];
  }

  long long F = 0, F2 = 0, curr_pow = 1, curr_pow2 = 1;
  for(int i = 0; i <= N; i++) {
    F += A[i] * curr_pow;
    F2 += A[i] * curr_pow2;
    F %= MOD;
    F2 %= MOD2;
    curr_pow = (curr_pow * 2) % MOD;
    curr_pow2 = (curr_pow2 * 2) % MOD2;
  }

  long long ways = 0; curr_pow = 1, curr_pow2 = 1;
  for(int i = 0; i <= N; i++) {
    // F(2) - A[i] * 2^k + k * 2^k = 0
    long long curr_orig = (curr_pow * A[i]) % MOD;
    long long numer = F - curr_orig;
    while(numer < 0) numer += MOD; numer %= MOD;
    long long denom = curr_pow;
    long long k = (numer * modpow(denom, MOD - 2)) % MOD;
    k *= -1;

    long long curr_orig2 = (curr_pow2 * A[i]) % MOD2;
    long long numer2 = F2 - curr_orig2;
    while(numer2 < 0) numer2 += MOD2; numer2 %= MOD2;

    long long cand_1 = k, cand_2 = (k + MOD) % MOD;
    long long abs_cand_1 = (cand_1 < 0 ? -cand_1 : cand_1), abs_cand_2 = (cand_2 < 0 ? -cand_2 : cand_2);

    if(i == N) {
      if(cand_1 == 0) cand_1 = K + 1;
      if(cand_2 == 0) cand_2 = K + 1;
    }

    if(abs_cand_1 <= K && (numer2 + cand_1 * curr_pow2) % MOD2 == 0) ways++;
    if(cand_1 != cand_2 && abs_cand_2 <= K && (numer2 + cand_2 * curr_pow2) % MOD2 == 0) ways++;

    curr_pow = (curr_pow * 2) % MOD;
    curr_pow2 = (curr_pow2 * 2) % MOD2;
  }

  cout << ways << endl;
}
