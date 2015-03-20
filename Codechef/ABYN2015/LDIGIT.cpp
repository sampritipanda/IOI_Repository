#include <stdio.h>

int main() {
  int T; scanf("%d", &T);

  while(T--){
    unsigned long long a, b; scanf("%llu %llu", &a, &b);
    unsigned long long rem = ((a % 9ULL) * (b % 9ULL)) % 9ULL;
    int ans;
    if(a == 0 || b == 0) ans = 0;
    else {
      if(rem == 0) ans = 9;
      else ans = rem;
    }
    printf("%d\n", ans);
  }
}
