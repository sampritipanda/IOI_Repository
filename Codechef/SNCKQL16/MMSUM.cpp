#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

long long A[100001];
long long dp[100001][2][2];
int N;

// i = index, j = deleted element, k = picked
long long solve(int i, int j, int k) {
  if(i > N) {
    if(k) return 0;
    else return LLONG_MIN/2;
  }
  if(dp[i][j][k] != LLONG_MIN) return dp[i][j][k];

  dp[i][j][k] = LLONG_MIN/2;

  if(k) dp[i][j][k] = 0;
  else dp[i][j][k] = max(dp[i][j][k], solve(i + 1, j, 0));

  dp[i][j][k] = max(dp[i][j][k], A[i] + solve(i + 1, j, 1));

  if(!j) dp[i][j][k] = max(dp[i][j][k], A[i] + solve(i + 2, 1, 1));

  return dp[i][j][k];
}

int main() {
  int T; scanf("%d", &T);

  while(T--) {
    scanf("%d", &N);

    for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);

    for(int i = 0; i <= N; i++) dp[i][0][0] = dp[i][0][1] = dp[i][1][1] = dp[i][1][1] = LLONG_MIN;

    printf("%lld\n", solve(1, 0, 0));
  }
}
