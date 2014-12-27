// Digital Counter

#include <stdio.h>

int main() {
  int n; scanf("%d", &n);
  int combinations[] = { 2, 7, 2, 3, 3, 4, 2, 5, 1, 2 };

  printf("%d\n", combinations[n/10] * combinations[n % 10]);
}
