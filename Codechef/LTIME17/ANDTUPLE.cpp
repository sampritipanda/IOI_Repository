// Physics Class

#include <stdio.h>

int main()
{
  int T; scanf("%d", &T);
  int K;
  unsigned long long N;
  int count = 0;

  while(T--) {
    scanf("%d %llu", &K, &N);

    if(K == 3){
      printf("%llu\n", (N/2 + 1) % 1000000009);
    }
    else {
      printf("10\n");
    }
  }
}
