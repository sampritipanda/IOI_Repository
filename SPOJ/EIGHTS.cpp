// Triple Fat Ladies

#include <stdio.h>

int main() {
  int suffixes[] = { 192, 442, 692, 942 };

  long long int T; scanf("%lld", &T);

  while(T--){
    long long int k; scanf("%lld", &k);

    if(k > 4) printf("%lld", (k-1)/4);
    printf("%d\n", suffixes[((k - 1) + 4) % 4]);
  }
}
