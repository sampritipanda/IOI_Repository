// Vanya and Cubes

#include <stdio.h>

int main() {
  int N; scanf("%d", &N);

  int height = 1;
  int curr_level = 0;
  while(true){
    curr_level += height;
    N -= curr_level;
    if(N <= 0) break;
    else height++;
  }

  if(N < 0) height--;

  printf("%d\n", height);
}
