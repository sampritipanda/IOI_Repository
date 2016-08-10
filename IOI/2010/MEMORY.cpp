#include "grader.h"
#include "memory.h"

int A[25];

void play() {
  for(int i = 0; i < 25; i++) A[i] = -1;

  int cnt = 0;
  for(int i = 1; i <= 50; i++) {
    int x = faceup(i) - 'A';
    cnt ^= 1;

    if(A[x] != -1) {
      if(cnt == 0) {
        faceup(i);
        cnt ^= 1;
      }
      faceup(A[x]);
      cnt ^= 1;
    }
    else {
      A[x] = i;
    }
  }
}
