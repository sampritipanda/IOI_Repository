// Sweet Deal

#include <stdio.h>

int main() {
  int T; scanf("%d", &T);

  while(T--){
    long long N, X; scanf("%lld %lld", &N, &X);
    long long C[N];
    for(int i = 0; i < N; i++) {
      scanf("%lld", &C[i]);
      C[i] -= X;
    }

    long long max_ending_here = C[0], max_sum = C[0];
    int max_sum_start = 0, max_sum_end = 0;
    for(int i = 1; i < N; i++){
      bool new_arr = false;
      if(C[i] > max_ending_here + C[i]){
        max_ending_here = C[i];
        new_arr = true;
      }
      else {
        max_ending_here += C[i];
      }

      if(max_ending_here > max_sum){
        max_sum = max_ending_here;
        if(new_arr) max_sum_start = max_sum_end = i;
        else max_sum_end++;
      }
    }

    long long profit = max_sum;
    printf("%lld\n", profit);
  }
}
