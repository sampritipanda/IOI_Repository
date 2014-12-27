// Player

#include <stdio.h>

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int N; scanf("%d", &N);
    double h_n = 0;
    for(int i = 1; i <= N; i++){
      h_n += 1.0/i;
    }

    printf("%lf\n", N * h_n);
  }
}
