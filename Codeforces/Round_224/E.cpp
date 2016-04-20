#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MOD 1000000007
#define INV_MOD_2 500000004

int orig_N;
long long C[51][51];
long long dp[51][51][2];

// N = number of vertices
// K = maximal matching required
// matched = current root used in matching?
long long solve(int N, int K, int matched) {
  if(N == 1) {
    // Current Matching isn't maximal if leaf is unmatched
    if(K == 0 && !matched) return 1;
    else return 0;
  }
  if(K < 0) return 0;

  if(dp[N][K][matched] != -1) return dp[N][K][matched];

  long long ans = 0;
  for(int i = 1; i < (N - 1); i++) {
    int j = (N - 1) - i;

    long long sum = 0;
    if(!matched) {
      for(int k = 0; k <= K; k++) {
        int k2 = K - k;
        (sum += solve(i, k, 1) * solve(j, k2, 1)) %= MOD;
      }
    }
    else {
      for(int k = 0; k <= K - 1; k++) {
        int k2 = (K - 1) - k;
        (sum += solve(i, k, 0) * solve(j, k2, 1)) %= MOD;
        (sum += solve(i, k, 1) * solve(j, k2, 0)) %= MOD;
        (sum += solve(i, k, 0) * solve(j, k2, 0)) %= MOD;
      }
    }
    sum = (sum * C[N - 1][i]) % MOD;
    ans = (ans + sum) % MOD;
  }
  ans = (ans * INV_MOD_2) % MOD;

  if(matched) {
    ans += solve(N - 1, K - 1, 0);
  }
  else {
    ans += solve(N - 1, K, 1);
  }
  ans %= MOD;

  if(N != orig_N) ans = (ans * N) % MOD;

  return dp[N][K][matched] = ans;
}

int main() {
  int N, K; cin >> N >> K;
  orig_N = N;

  for(int i = 0; i <= 50; i++) {
    C[i][0] = C[i][i] = 1;
    for(int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }

  memset(dp, -1, sizeof dp);

  cout << (solve(N, K, 0) + solve(N, K, 1)) % MOD << endl;
}
