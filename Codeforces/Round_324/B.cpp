#include <iostream>

using namespace std;

#define MOD 1000000007

int main() {
  int N; cin >> N;

  long long ans = 1;
  for(int i = 1; i <= 3*N; i++) {
    ans = (ans * 3) % MOD;
  }

  long long b = 1;
  for(int i = 1; i <= N; i++) {
    b = (b * (6 + 1)) % MOD;
  }

  cout << (ans - b + MOD) % MOD << endl;
}
