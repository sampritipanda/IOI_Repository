#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

long long A[1000001];

long long modpow(long long base, long long exp) {
  long long result = 1;
  base %= MOD;

  while(exp) {
    if(exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }

  return result;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N, x; long long M; cin >> N >> x >> M;
    M--;
    M %= MOD;

    for(int i = 1; i <= N; i++) {
      cin >> A[i];
      A[i] %= MOD;
    };

    long long ans = A[x];
    long long prod = 1;
    long long fact = 1;

    for(int i = 1; i < x; i++) {
      fact = (fact * i) % MOD;
      prod = (prod * (M + i)) % MOD;

      long long curr = A[x - i];
      curr = (curr * prod) % MOD;
      curr = (curr * modpow(fact, MOD - 2)) % MOD;

      ans += curr;
      ans %= MOD;
    }

    cout << ans << endl;
  }
}
