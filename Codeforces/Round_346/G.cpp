#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007

long long A[1000002];
long long dp[1000002];
// if A[i] > A[i + 1], dp2[i] = number of arrangements where i and i + 1 and not connected
long long dp2[1000002];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];
  dp[N + 1] = 2000000000;

  dp[0] = 0;
  dp[1] = A[1] - 1;
  if(A[1] > A[2]) dp2[1] = A[1] - A[2];

  for(int i = 2; i <= N; i++) {
    dp[i] += ((1 + dp[i - 1]) * (A[i] - 1)) % MOD;
    dp[i] %= MOD;

    if(A[i - 1] > A[i]) {
      dp[i] -= ((dp2[i - 1]) * (A[i] - 1)) % MOD;
    }
    else if(A[i] > A[i - 1]) {
      dp[i] -= (((A[i] - A[i - 1]) * dp[i - 1])) % MOD;
    }
    while(dp[i] < 0) dp[i] += MOD;
    dp[i] %= MOD;

    if(A[i] > A[i + 1]) {
      dp2[i] = A[i] - A[i + 1];
      if(A[i - 1] >= A[i]) {
        dp2[i] += (A[i] - A[i + 1]) * (dp[i - 1] - dp2[i - 1]) % MOD;
      }
      else if(A[i] > A[i - 1]){
        if(A[i - 1] > A[i + 1]) {
          dp2[i] += (A[i - 1] - A[i + 1]) * dp[i - 1];
        }
      }

      while(dp2[i] < 0) dp2[i] += MOD;
      dp2[i] %= MOD;
    }
  }

  long long ans = 0;
  for(int i = 1; i <= N; i++) ans = (ans + dp[i]) % MOD;
  cout << ans << endl;
}


/*

      x
      x
      x  x
   x  x  x  x  x

*/
