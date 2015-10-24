// Task 1

#include <stdio.h>

int main() {
  int slices[8];
  for(int i = 0; i < 8; i++) scanf("%d", &slices[i]);

  int max_num = 0;
  for(int i = 0; i < 8; i++){
    int sum = 0;
    sum += slices[(i + 0) % 8];
    sum += slices[(i + 1) % 8];
    sum += slices[(i + 2) % 8];
    sum += slices[(i + 3) % 8];

    if(sum > max_num) max_num = sum;
  }

  printf("%d\n", max_num);
}
