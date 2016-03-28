#include <iostream>
#include <algorithm>

#define MOD 1000000007

using namespace std;

long long ans[31][31];
long long fact[31];

int main() {
  fact[0] = 1;
  for(int i = 1; i <= 30; i++) fact[i] = (fact[i - 1] * i) % MOD;

  for(int mask = 0; mask < (1 << 18); mask++) {
  }
}
