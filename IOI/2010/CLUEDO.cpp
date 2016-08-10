#include "grader.h"

void Solve(){
  int i = 1, j = 1, k = 1;
  int res = Theory(i, j, k);
  while(res != 0) {
    if(res == 1) {
      i++;
    }
    else if(res == 2) {
      j++;
    }
    else {
      k++;
    }
    res = Theory(i, j, k);
  }
}
