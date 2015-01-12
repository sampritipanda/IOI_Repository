// AP-GP

#include <stdio.h>

int main() {
  int x, y, z;

  while(true) {
    scanf("%d %d %d", &x, &y, &z);
    if(x == 0 && y == 0 && z == 0) break;

    if(y - x == z - y){
      printf("AP %d\n", z + (y - x));
    }
    else {
      printf("GP %d\n", z * (y / x));
    }
  }
}
