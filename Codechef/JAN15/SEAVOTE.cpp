// Sereja and Votes

#include <stdio.h>

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int N; scanf("%d", &N);
    int B[N];

    int sum_lo = 0, sum_hi = 0;
    for(int i = 0; i < N; i++){
      scanf("%d", &B[i]);
      if(B[i] > 0) {
        sum_lo += B[i] - 1;
        sum_hi += B[i];
      }
    }

    if(sum_lo < 100 && 100 <= sum_hi) printf("YES\n");
    else printf("NO\n");
  }
}
