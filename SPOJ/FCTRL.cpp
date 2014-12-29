// Factorial

#include <stdio.h>

int main() {
  long long table[14] = {1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625, 1220703125};

  int T; scanf("%d", &T);

  while(T--){
    long long N; scanf("%lld", &N);
    long long zeroes = 0;
    for(int i = 1; i <= 13; i++){
      zeroes += N/table[i];
    }

    printf("%lld\n", zeroes);
  }
}
