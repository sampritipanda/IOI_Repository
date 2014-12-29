// Feynman

#include <stdio.h>

int main() {
  long long N;

  while(true){
    scanf("%lld", &N);
    if(N == 0) break;

    long long squares = (N * (N + 1) * (2 * N + 1))/6;

    printf("%lld\n", squares);
  }
}
