#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define MOD 1000000007

long long modpow(long long a, long long b, long long c) {
  long long result = 1;
  while(b > 0) {
    if(b & 1) result = (result * a) % c;
    a = (a * a) % c;
    b >>= 1;
  }
  return result;
}

map<int, int> p;

int main() {
  int M; cin >> M;
  for(int i = 0; i < M; i++) {
    int P; cin >> P;
    p[P]++;
  }

  bool square = true;

  long long num = 1;
  for(auto it: p) {
    if(it.second % 2 == 1) square = false;
    num = (num * (it.second + 1)) % MOD;
  }
  if(square) num = (num - 1 + MOD) % MOD;
  num = (num * modpow(2, MOD - 2, MOD)) % MOD;

  long long ans = 1;

  for(auto it: p) {
    ans = (ans * modpow(modpow(it.first, it.second, MOD), num, MOD - 1)) % MOD;
  }

  if(square) {
    for(auto it: p) {
      ans = (ans * modpow(it.first, it.second/2, MOD)) % MOD;
    }
  }

  cout << ans << endl;
}
