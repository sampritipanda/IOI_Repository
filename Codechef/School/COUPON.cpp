// Online Shopping

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int N, M; scanf("%d %d", &N, &M);
    long long price[N + 1][M + 1], discount[N + 1][M + 1];

    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= M; j++){
        scanf("%lld", &price[i][j]);
      }
    }

    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= M; j++){
        scanf("%lld", &discount[i][j]);
      }
    }

    long long dp[N + 1][M + 1];
    for(int i = 1; i <= M; i++) dp[1][i] = price[1][i];

    for(int i = 2; i <= N; i++){
      long long min_price_prev = dp[i - 1][1];
      for(int j = 1; j <= M; j++){
        if(dp[i - 1][j] < min_price_prev) min_price_prev = dp[i - 1][j];
      }

      for(int j = 1; j <= M; j++){
        dp[i][j] = min(min_price_prev + price[i][j], dp[i - 1][j] + max(price[i][j] - discount[i - 1][j], 0LL));
      }
    }

    long long answer = dp[N][1];
    for(int i = 1; i <= M; i++){
      if(dp[N][i] < answer) answer = dp[N][i];
    }

    printf("%lld\n", answer);
  }
}
