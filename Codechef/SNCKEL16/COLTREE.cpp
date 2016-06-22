#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define MOD 1000000007

long long C[51][51];
long long F[51];

int main() {
  F[0] = 1;
  for(int i = 1; i <= 50; i++) F[i] = (F[i - 1] * i) % MOD;

  C[0][0] = 1;
  for(int i = 1; i <= 50; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) C[i][j] = 1;
      else {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
      }
    }
  }

  int T; cin >> T;

  while(T--) {
    int N, K; cin >> N >> K;

    for(int i = 0; i < N - 1; i++) {
      int u, v; cin >> u >> v;
    }

    long long ans = 0;
    for(int k = 1; k <= min(N, K); k++) {
      long long curr = F[k];
      (curr *= C[N - 1][k - 1]) %= MOD;
      (curr *= C[K][k]) %= MOD;

      (ans += curr) %= MOD;
    }
    cout << ans << endl;
  }
}
