// 78 Points

#include "grader.h"

int HC(int N){
  int L = 1, R = N;
  int L_G = Guess(1), R_G = -2;

  while(L < R) {
    if(L_G == -2) {
      L_G = Guess(L);
      if(L_G == 0) return (L + R)/2;
      else if(L_G < 0) {
        L = (L + R)/2 + 1;
        if(L < R) {
          R_G = Guess(R);
          L_G = -2;
        }
      }
      else {
        R = (L + R + 1)/2 - 1;
        R_G = -2;
      }
    }
    else {
      R_G = Guess(R);
      if(R_G == 0) return (L + R)/2;
      else if(R_G < 0) {
        R = (L + R + 1)/2 - 1;
        if(L < R) {
          L_G = Guess(L);
          R_G = -2;
        }
      }
      else {
        L = (L + R)/2 + 1;
        L_G = -2;
      }
    }
  }
  return L;
}
