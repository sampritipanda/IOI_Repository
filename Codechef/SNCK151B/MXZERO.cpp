// Make XOR zero

#include <stdio.h>

using namespace std;

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int N; scanf("%d", &N);
    int A[N];
    int xor_sum = 0;
    for(int i = 0; i < N; i++) {
      scanf("%d", &A[i]);
      xor_sum ^= A[i];
    }

    int ways = 0;
    for(int i = 0; i < N; i++) {
      if(xor_sum ^ A[i] == 0) ways++;
    }
    printf("%d\n", ways);
  }
}
