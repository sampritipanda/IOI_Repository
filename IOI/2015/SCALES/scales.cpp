#include "scales.h"

#include <algorithm>

using namespace std;

void init(int T) {
}
void orderCoins() {
  int W[6];
  int A[3], B[3];

  A[0] = getLightest(1, 2, 3), A[2] = getHeaviest(1, 2, 3);
  A[1] = (1 + 2 + 3) - A[0] - A[2];

  B[0] = getLightest(4, 5, 6), B[2] = getHeaviest(4, 5, 6);
  B[1] = (4 + 5 + 6) - B[0] - B[2];

  int i = 0, j = 0;

  W[0] = getLightest(A[i], A[i + 1], B[j]);
  if(W[0] == A[i]) i++;
  else j++;

  W[1] = getLightest(A[i], A[i + 1], B[j]);
  if(W[1] == A[i]) i++;
  else j++;


  answer(W);
}
