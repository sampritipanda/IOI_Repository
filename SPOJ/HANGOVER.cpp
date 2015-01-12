// Hangover

#include <stdio.h>

int main() {
  double N;

  while(true) {
    scanf("%lf", &N);
    if(N == 0.0) break;

    double curr = 0;
    int count = 1;

    while(curr <= N){
      count++;
      curr += 1.0/count;
    }

    printf("%d card(s)\n", count - 1);
  }
}
