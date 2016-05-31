#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S;
int N;
bool dp[41][41];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> S;
  N = S.length();

  for(int i = 0; i < N; i++) dp[i][i] = true;
  for(int i = 0; i < N - 1; i++) {
    if(S[i] == S[i + 1]) dp[i][i + 1] = true;
  }
  for(int i = 0; i < N - 2; i++) {
    if(S[i] == S[i + 2]) dp[i][i + 2] = true;
  }

  for(int len = 4; len <= N; len++) {
    for(int i = 0; i <= N - len; i++) {
      int j = i + len - 1;
      if(S[i] == S[j]) dp[i][j] = dp[i + 1][j - 1];
    }
  }

  int ans = 0;
  for(int i = 0; i < N; i++) {
    for(int j = i; j < N; j++) {
      if(dp[i][j]) ans = max(ans, j - i + 1);
    }
  }

  cout << ans << endl;
}
