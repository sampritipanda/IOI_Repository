#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int N, K;
int A[100001];
long long P[100001];
long long dp[10002][202];
int nxt[10002][202];

int main() {
  scanf("%d %d", &N, &K);
  for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
  for(int i = 1; i <= N; i++) P[i] = P[i - 1] + A[i];

  dp[0][1] = LLONG_MIN/2;
  for(int j = 2; j <= K + 1; j++) {
    dp[0][j] = LLONG_MIN/2;
    for(int i = 1; i <= N; i++) {
      dp[i][j] = LLONG_MIN/2;
      for(int k = 1; k <= i; k++) {
        long long curr = P[i] * P[k - 1] - P[k - 1] * P[k - 1] + dp[k - 1][j - 1];
        if(curr > dp[i][j]) {
          dp[i][j] = curr;
          nxt[i][j] = k;
        }
      }
    }
  }

  printf("%lld\n", dp[N][K + 1]);

  int i = N, j = K + 1;
  while(j > 1) {
    printf("%d ", nxt[i][j] - 1);
    i = nxt[i][j] - 1;
    j--;
  }
  printf("\n");
}
