// Candy III

#include <stdio.h>

int main() {
  unsigned long long int T; scanf("%llu", &T);

  while(T--){
    unsigned long long int N; scanf(" %llu", &N);

    unsigned long long int sum = 0;
    for(int i = 0; i < N; i++){
      unsigned long long int temp; scanf("%llu", &temp);
      sum = (sum + temp) % N;
    }

    if(N == 0) printf("YES\n");
    else if(sum % N == 0) printf("YES\n");
    else printf("NO\n");
  }
}
