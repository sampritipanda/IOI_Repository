// Calvin's Game

#include <stdio.h>

inline int max(int a, int b){
  return (a > b) ? a : b;
}

int main() {
  int N, k; scanf("%d %d", &N, &k);
  k--;

  int sequence[N];
  int forward_dp[N];          // forward_dp[i] = Max score in forward phase starting at K, ending at i.
  int backward_dp[N];         // backward_dp[i] = Max score in backward phase with backward phase starting at i ending a 0

  for(int i = 0; i < N; i++) scanf("%d", &sequence[i]);

  forward_dp[k] = 0;
  forward_dp[k + 1] = forward_dp[k] + sequence[k + 1];

  for(int i = k + 2; i < N; i++){
    forward_dp[i] = max(forward_dp[i - 2], forward_dp[i - 1]) + sequence[i];
  }

  backward_dp[0] = 0;
  backward_dp[1] = sequence[0];
  for(int i = 2; i < N; i++){
    backward_dp[i] = max(sequence[i - 1] + backward_dp[i - 1], sequence[i - 2] + backward_dp[i - 2]);
  }

  int maxScore = backward_dp[k] + forward_dp[k];
  for(int i = k + 1; i < N; i++){
    if((backward_dp[i] + forward_dp[i]) > maxScore) maxScore = (backward_dp[i] + forward_dp[i]);
  }

  printf("%d\n", maxScore);
}

