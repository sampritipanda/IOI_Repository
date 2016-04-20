#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007LL

long long modpow(long long base, long long exp) {
  long long res = 1;

  while(exp) {
    if(exp & 1) res = (res * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }

  return res;
}

int main() {
  int T; cin >> T;

  while(T--) {
    long long N, K; cin >> N >> K;

    cout << (K * modpow(K - 1, N - 1)) % MOD << endl;
  }
}
