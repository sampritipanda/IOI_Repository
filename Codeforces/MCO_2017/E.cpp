#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007LL

string S;
int N;
long long dp[1 << 18][18];
int s, e;

long long solve(int mask, int i) {
  if(mask == (1 << N) - 1) {
    if(i == e) return 1;
    else return 0;
  }
  if(dp[mask][i] != -1) return dp[mask][i];

  dp[mask][i] = 0;
  for(int j = 0; j < N; j++) {
    if(S[i] == 'L' && j >= i) continue;
    if(S[i] == 'R' && j <= i) continue;
    if(mask & (1 << j)) continue;

    dp[mask][i] += solve(mask | (1 << j), j);
    dp[mask][i] %= MOD;
  }
  return dp[mask][i];
}

int main() {
  cin >> S;
  N = S.length();
  cin >> s >> e; s--, e--;

  for(int i = 0; i < (1 << N); i++) {
    for(int j = 0; j < N; j++) {
      dp[i][j] = -1;
    }
  }

  cout << solve(1 << s, s) << endl;
}
