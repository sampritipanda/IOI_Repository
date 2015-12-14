#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define MOD 1000000007LL

long long ways[1 << 10];
long long power[100001];
long long dp[1 << 10][1 << 10];

long long solve(int i, int j) {
  if(j == (1 << 10)) return (i == 0 ? 1 : 0);
  if(dp[i][j] != -1) return dp[i][j];

  if(ways[j] == 0) return dp[i][j] = solve(i, j + 1);
  else {
    return dp[i][j] = (solve(i ^ j, j + 1) * power[ways[j]] + solve(i, j + 1) * power[ways[j]]) % MOD;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  power[0] = 0; power[1] = 1;
  for(int i = 2; i <= 100000; i++) power[i] = (power[i - 1] * 2) % MOD;

  int T; cin >> T;

  while(T--) {
    for(int i = 0; i < (1 << 10); i++) {
      ways[i] = 0;
      for(int j = 0; j < (1 << 10); j++) {
        dp[i][j] = -1;
      }
    }

    string S; cin >> S;
    int start = 0;
    for(int i = 0; i < 10; i++) {
      if(S[i] == 'w') start |= (1 << i);
    }

    int N; cin >> N;
    for(int i = 0; i < N; i++) {
      string F; cin >> F;
      int curr = 0;
      for(int j = 0; j < 10; j++) {
        if(F[j] == '+') curr |= (1 << j);
      }
      ways[curr]++;
    }

    cout << solve(start, 0) << endl;
  }
}
