#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

string keys[10];
int D[10][10];
string M;
int N;
long long dp[1000001][10];
long long press_cost[10][26];

long long solve(int i, int key) {
  if(i == N) return 0;

  if(dp[i][key] != -1) return dp[i][key];

  long long ans = LLONG_MAX/2;
  for(int j = 1; j <= 9; j++) {
    if(press_cost[j][M[i] - 'a'] != LLONG_MAX/2) {
      ans = min(ans, D[key][j] + press_cost[j][M[i] - 'a'] + solve(i + 1, j));
    }
  }

  dp[i][key] = ans;
  return ans;
}

int main() {
  int T; cin >> T;

  while(T--) {
    memset(D, 0, sizeof D);

    for(int i = 1; i <= 9; i++) cin >> keys[i];
    for(int i = 1; i <= 9; i++) {
      for(int j = 1; j <= 9; j++) {
        cin >> D[i][j];
      }
    }

    cin >> M;
    N = M.length();
    for(int i = 0; i <= N; i++) {
      for(int j = 0; j <= 9; j++) {
        dp[i][j] = -1;
      }
    }

    for(int i = 0; i <= 9; i++) {
      for(int j = 0; j < 26; j++) {
        press_cost[i][j] = LLONG_MAX/2;
      }
    }

    for(int i = 1; i <= 9; i++) {
      for(int j = 0; j < keys[i].length(); j++) {
        press_cost[i][keys[i][j] - 'a'] = min(press_cost[i][keys[i][j] - 'a'], (long long)j + 1);
      }
    }

    long long ans = solve(0, 0);
    if(ans >= LLONG_MAX/2) cout << -1 << endl;
    else cout << ans << endl;
  }
}

