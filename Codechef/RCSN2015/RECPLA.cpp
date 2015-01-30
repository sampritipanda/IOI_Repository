// Placements

#include <stdio.h>
#include <limits.h>

int main() {
  int T; scanf("%d", &T);

  while(T--) {
    long long N, C; scanf("%lld %lld", &N, &C);
    long long A[N];
    for(int i = 0; i < N; i++) scanf("%lld", &A[i]);

    long long limit = 1LL << N;
    long long min_close = LONG_MAX;
    for(long long i = 0; i < limit; i++){
      bool flag = true;
      long long sum = 0;
      for(int j = 0; j < N; j++){
        if(i & (1LL << j)){
          sum += A[j];
          if(sum > C){
            flag = false;
            break;
          }
        }
      }
      if(flag && (C - sum < min_close)) min_close = C - sum;
      if(min_close == 0) break;
    }

    printf("%lld\n", min_close);
  }
}
