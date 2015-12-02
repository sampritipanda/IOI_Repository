#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007

long long modpow(long long base, long long exp) {
  long long result = 1;

  while(exp > 0) {
    if(exp & 1) result = (result * base)  % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }

  return result;
}

int main() {
  long long N, P; cin >> N >> P;

  long long A = 1;
  for(int i = 1; i <= N; i++) A = (A * i) % MOD;

  long long result = (P * modpow(A, MOD - 2)) % MOD;
  cout << result << endl;
}
