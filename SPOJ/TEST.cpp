// Life, the Universe, and Everything

#include <stdio.h>

int main() {
  while(true) {
    int num; scanf("%d", &num);
    if(num == 42) break;
    else printf("%d\n", num);
  }
}
