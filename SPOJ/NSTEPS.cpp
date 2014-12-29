// Number Steps

#include <stdio.h>

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int x, y; scanf("%d %d", &x, &y);

    if(x == y){
      if(x % 2 == 1){
        printf("%d\n", x * 2 - 1);
      }
      else {
        printf("%d\n", x * 2);
      }
    }
    else if(x - y == 2){
      if(x % 2 == 1){
        printf("%d\n", x + y - 1);
      }
      else {
        printf("%d\n", x + y);
      }
    }
    else {
      printf("No Number\n");
    }
  }
}
