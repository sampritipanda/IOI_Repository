#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MOD 1000000007

long long dp[1001]; // dp[i] = no. of ways to split 1..i
int dp2[1001]; // dp2[i] = min no. splits required for 1..i
int S[1001];
int A[1001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  string str; cin >> str;
  for(int i = 0; i < N; i++) S[i + 1] = str[i] - 'a' + 1;
  for(int i = 1; i <= 26; i++) cin >> A[i];

  dp[0] = 1;
  dp2[0] = 0;
  int max_sub = 0;

  for(int i = 1; i <= N; i++) {
    dp[i] = 0;
    dp2[i] = N + 1;

    bool pres[27];
    for(int k = 1; k <= 26; k++) pres[k] = false;

    for(int j = i; j >= 1; j--) {
      pres[S[j]] = true;
      int len = i - j + 1;
      bool valid = true;
      for(int k = 1; k <= 26; k++) {
        if(pres[k] && len > A[k]) valid = false;
      }
      if(!valid) break;

      max_sub = max(max_sub, len);
      dp[i] = (dp[i] + dp[j - 1]) % MOD;
      dp2[i] = min(dp2[i], dp2[j - 1] + 1);
    }
  }

  cout << dp[N] << endl;
  cout << max_sub << endl;
  cout << dp2[N] << endl;
}
