// XOR with Subset

#include <stdio.h>

int main() {
  int T; scanf("%d", &T);
  int N, K;

  while(T--){
    scanf("%d %d", &N, &K);
    int sequence[N];

    for(int i = 0; i < N; i++) scanf("%d", &sequence[i]);

    int max = 0;
    for(long long i = 0; i < (1LL << N); i++){
      int curr = 0;
      for(long long k = 0; k < N; k++){
        if((i & (1LL << k)) > 0) {
          curr ^= sequence[k];
        }
      }
      curr = K ^ curr;
      if(curr > max) max = curr;
    }

    printf("%d\n", max);
  }
}
