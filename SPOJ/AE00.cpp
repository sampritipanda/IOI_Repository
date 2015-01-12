// Rectangles

#include <stdio.h>

int main() {
  int N; scanf("%d", &N);
  long long rectangles = 1;
  for(int i = 2; i <= N; i++){
    for(int j = 1; j*j <= i; j++){
      if(i % j == 0) rectangles++;
    }
  }

  printf("%lld\n", rectangles);
}
