#include <iostream>
#include <climits>
#include <cassert>
#include <algorithm>

using namespace std;

long long A[100000];
long long dp[250001];

int main() {
  int N, start, D; cin >> N >> start >> D;
  assert(start == 0);

  for(int i = 0; i < N; i++) cin >> A[i];

  for(int i = 0; i <= D; i++) dp[i] = LLONG_MIN/2;

  long long ans = 0;

  dp[0] = 0;
  dp[1] = A[0];

  ans = max(ans, A[0]);

  for(int i = 1; i < min(N, D); i++) {
    for(int j = D; j >= i + 1; j--) {
      dp[j] = max(dp[j - 1], A[i] + dp[j - 2]);
    }
    ans = max(ans, dp[D]);
    dp[i] = 0;
  }

  cout << ans << endl;
}
