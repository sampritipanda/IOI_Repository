// Pair Stones

#include <stdio.h>

int main(){
  int R; scanf("%d", &R);
  int N; scanf("%d", &N);

  int M;

  for(int i = 0; i < R; i++){
    for(int j = 0; j < R; j++){
      scanf("%d", &M);

      if(M == N) {
        printf("YES\n");
        return 0;
      }
    }
  }
  printf("NO\n");
}
