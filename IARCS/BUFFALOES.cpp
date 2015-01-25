// Speculating on Buffaloes

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int N, K; scanf("%d %d", &N, &K);
  long long buffaloes[N + 1];
  for(int i = 1; i <= N; i++) scanf("%lld", &buffaloes[i]);

  K /= 2;

  long long dp[N + 1][K + 1];

  for(int i = 0; i <= N; i++){
    for(int j = 0; j <= K; j++){
      dp[i][j] = -1;
    }
  }

  for(int i = 0; i <= K; i++) dp[N][i] = 0;
  for(int i = 1; i <= N; i++) dp[i][0] = 0;

  for(int i = N - 1; i >= 1; i--){
    for(int k = K; k >= 1; k--){
      long long max_profit = dp[i + 1][k];
      for(int j = i + 1; j < N; j++){
        max_profit = max(max_profit, buffaloes[j] - buffaloes[i] + dp[j + 1][k - 1]);
      }
      max_profit = max(max_profit, buffaloes[N] - buffaloes[i]);
      dp[i][k] = max_profit;
    }
  }

  printf("%lld\n", dp[1][K]);
}
