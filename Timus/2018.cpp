#include <iostream>
#include <cstring>

using namespace std;

#define MOD 1000000007

int N, a, b;
long long memo[50001][2];

long long solve(int i, int type) {
  if(i == N) return 1;
  if(memo[i][type] != -1) return memo[i][type];

  long long ans = 0;
  if(type == 0) {
    for(int j = i + 1; j <= min(N, i + a); j++) {
      ans += solve(j, 1);
      ans %= MOD;
    }
  }
  else {
    for(int j = i + 1; j <= min(N, i + b); j++) {
      ans += solve(j, 0);
      ans %= MOD;
    }
  }

  memo[i][type] = ans;
  return ans;
}

int main() {
  memset(memo, -1, sizeof memo);
  cin >> N >> a >> b;

  cout << (solve(0, 0) + solve(0, 1)) % MOD << endl;
}
