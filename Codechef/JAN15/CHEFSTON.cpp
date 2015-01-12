// Chef and Stones

#include <stdio.h>

int main() {
  int T; scanf("%d", &T);

  while(T--){
    unsigned long long N, K; scanf("%llu %llu", &N, &K);
    unsigned long long A[N], B[N];

    for(int i = 0; i < N; i++) scanf("%llu", &A[i]);
    for(int i = 0; i < N; i++) scanf("%llu", &B[i]);

    unsigned long long max_profit = 0;

    for(int i = 0; i < N; i++){
      unsigned long long profit = K/A[i] * B[i];
      if(profit > max_profit) max_profit = profit;
    }

    printf("%llu\n", max_profit);
  }
}
