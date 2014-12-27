// Modular Equations

#include <stdio.h>

int main() {
  int a, b; scanf("%d %d", &a, &b);

  int c = a - b;
  if(c == 0) printf("infinity\n");
  else {
    int count = 0;
    for(int i = b + 1; i <= a - b; i++){
      if(c % i == 0) count++;
    }
    printf("%d\n", count);
  }
}
