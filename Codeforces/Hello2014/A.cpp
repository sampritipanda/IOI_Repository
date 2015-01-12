// Cursed Query

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int N, Q; scanf("%d %d", &N, &Q);
  unsigned long long A[N + 1];

  A[0] = 0;
  for(int i = 1; i <= N; i++) {
    scanf("%llu", &A[i]);
    A[i] += A[i - 1];
  }

  for(int i = 0; i < Q; i++){
    unsigned long long t; scanf("%llu", &t);
    auto light_id = lower_bound(A, A + N, t);
    if(*light_id == t) {
      unsigned long long light_id_2 = (light_id - A + 1) % N;
      if(light_id_2 == 0) light_id_2 = N;
      printf("%lld\n", light_id_2);
    }
    else {
      unsigned long long light_id_2 = (light_id - A) % N;
      if(light_id_2 == 0) light_id_2 = N;
      printf("%lld\n", light_id_2);
    }
  }
}
