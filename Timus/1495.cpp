#include <iostream>
#include <algorithm>

using namespace std;

int precalc[31];
int N;
char dp[31][1000001];   // -1 = not visited, 0 = not possible, 1 = digit 1 used, 2 = 2 used

// i = answer for digits i..1 (i <= 30), j = mod left
int solve(int i, int j) {
  if(i == 0) {
    if(j == 0) return 1;
    else return 0;
  }
  if(dp[i][j] != -1) return dp[i][j];

  dp[i][j] = 0;
  int new_mod = (j + 1 * precalc[i]) % N;
  if(solve(i - 1, new_mod) >= 1) {
    dp[i][j] = 1;
  }
  else {
    int new_mod = (j + 2 * precalc[i]) % N;
    if(solve(i - 1, new_mod) >= 1) {
      dp[i][j] = 2;
    }
  }

  return dp[i][j];
}

int main() {
  cin >> N;

  precalc[1] = 1 % N;
  for(int i = 2; i <= 30; i++) precalc[i] = (precalc[i - 1] * 10) % N;

  for(int i = 0; i <= 30; i++) {
    for(int j = 0; j <= 1000000; j++) {
      dp[i][j] = -1;
    }
  }

  string ans = "Impossible";
  for(int i = 1; i <= 30; i++) {
    if(solve(i, 0) >= 1) {
      ans = "";
      int curr_mod = 0;
      for(int j = i; j > 0; j--) {
        ans += ('0' + dp[j][curr_mod]);
        curr_mod = (curr_mod + dp[j][curr_mod] * precalc[j]) % N;
      }
      break;
    }
  }

  cout << ans << endl;
}
