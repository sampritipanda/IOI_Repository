#include <stdio.h>

using namespace std;

unsigned long long arr[50000000];

int main() {
  int Q; unsigned S, A, B; scanf("%d %d %d %d", &Q, &S, &A, &B);
  unsigned T, x, y;

  unsigned long long ans = 0;
  while(Q--) {
    if(ans == 465) {
      x = 5;
    }
    T = S/2;
    x = T/64;
    y = T % 64;
    if(S & 1) {
      if(!(arr[x] & (1ULL << y))) {
        ans += T;
        arr[x] |= (1ULL << y);
      }
    }
    else {
      if(arr[x] & (1ULL << y)) {
        ans -= T;
        arr[x] &= ~(1ULL << y);
      }
    }

    S = A*S + B;
  }

  printf("%llu\n", ans);
}
