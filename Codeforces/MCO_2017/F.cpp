#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007LL

int N;
long long fac[2001];
long long inv_fac_sqr[2001];

long long modpow(long long base, long long exp) {
  long long res = 1;
  while(exp > 0) {
    if(exp & 1) res = (res * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return res;
}

long long C(long long A, long long B) {
  long long ans = 1;
  if(A < B) return ans;
  for(int i = A; i >= A - B + 1; i--) ans = (ans * i) % MOD;
  ans = (ans * modpow(fac[B], MOD - 2)) % MOD;
  return ans;
}

vector<long long> merge(vector<long long> A, vector<long long> B) {
  vector<long long> res(N + 1);
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= i; j++) {
      res[i] += (A[i - j] * B[j]) % MOD;
      res[i] %= MOD;
    }
  }
  return res;
}

int main() {
  fac[0] = 1;
  for(int i = 1; i <= 2000; i++) fac[i] = (fac[i - 1] * i) % MOD;
  for(int i = 0; i <= 2000; i++) {
    inv_fac_sqr[i] = modpow((fac[i] * fac[i]) % MOD, MOD - 2);
  }

  int K; cin >> N >> K;

  vector<long long> base(N + 1);
  base[0] = 1;
  for(int i = 1; i <= N; i++) base[i] = inv_fac_sqr[i];
  vector<long long> res = base;
  int exp = K - 1;
  while(exp > 0) {
    if(exp & 1) res = merge(res, base);
    base = merge(base, base);
    exp >>= 1;
  }

  long long ans = (fac[N] * fac[N]) % MOD;
  ans = (ans * res[N]) % MOD;
  cout << ans << endl;
}
