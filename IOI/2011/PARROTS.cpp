// 81 Points

#include "grader.h"

void encode(int N, int A[]) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 8; j++) {
      if(A[i] & (1 << j)) {
        send((i << 3) + j);
      }
    }
  }
}

void decode(int N, int L, int X[]) {
  int* A = new int[N];
  for(int k = 0; k < L; k++) {
    int i = X[k] >> 3;
    int j = X[k] % (1 << 3);
    A[i] |= (1 << j);
  }

  for(int i = 0; i < N; i++) output(A[i]);
}
