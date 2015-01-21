// Spiderman and Jumping

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int N; scanf("%d", &N);
  long long A[N];
  long long dp[N];

  for(int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
    dp[i] = 1000000000000;
  }

  dp[0] = 0;
  for(int i = 1; i < N; i++){
    for(long long j = 1; j <= i; j *= 2){
      dp[i] = min(dp[i], dp[i - j] + abs(A[i] - A[i - j]));
    }
  }

  printf("%lld\n", dp[N - 1]);
}
