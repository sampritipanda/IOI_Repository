// Little Chef and the King

#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

unsigned long long small_pow(unsigned long long a, unsigned long long b){
  unsigned long long result = 1;
  while(b--) result *= a;
  return result;
}

int main() {
  int T; scanf("%d", &T);

  while(T--){
    unsigned long long N, K; scanf("%llu %llu", &N, &K);

    unsigned long long curr = floor(log(N)/log(K)), count = 0;
    while(N > 0){
      unsigned long long price = small_pow(K, curr);
      unsigned long long num_coins = min(N/price, K);
      count += N/price;
      N %= price;
      curr--;
    }

    printf("%llu\n", count);
  }
}
