/*
ID: sampdin1
PROG: ride
LANG: C++11
*/

#include <stdio.h>
#include <string.h>

int main() {
  freopen("ride.in", "r", stdin);
  freopen("ride.out", "w", stdout);

  char a[10], b[10];
  scanf(" %s", a);
  scanf(" %s", b);

  int N = strlen(a), M = strlen(b);
  int val_a = 1, val_b = 1;
  for(int i = 0; i < N; i++) {
    val_a *= a[i] - 'A' + 1;
  }
  for(int i = 0; i < M; i++) {
    val_b *= b[i] - 'A' + 1;
  }

  if(val_a % 47 == val_b % 47) printf("GO\n");
  else printf("STAY\n");

  fclose(stdin);
  fclose(stdout);
}
