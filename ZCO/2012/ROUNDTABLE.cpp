#include <stdio.h>

using namespace std;

inline int min(int a, int b){
  return (a < b ? a : b);
}

int main() {
  int N; scanf("%d", &N);
  int desserts[N], dp[N];

  for(int i = 0; i < N; i++){
    scanf("%d", &desserts[i]);
  }

  if(N == 1){
    printf("%d\n", desserts[0]);
  }
  else {
    dp[0] = desserts[0];
    dp[1] = dp[0] + desserts[1];

    for(int i = 2; i < N; i++){
      dp[i] = min(dp[i - 1], dp[i - 2]) + desserts[i];
    }
    printf("%d\n", min(min(dp[0], dp[N - 1]), dp[N - 2]));
  }
}
