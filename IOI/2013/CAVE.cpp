#include "grader.h"
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

int _N;

int _tryCombination(int S[]) {
  int ans = tryCombination(S);
  if(ans == -1) ans = _N + 1;
  return ans;
}

int flipCheck(int S[], int D[], int lim, int L, int R) {
  for(int i = L; i <= R; i++) {
    if(D[i] != -1 && D[i] < lim) continue;
    S[i] ^= 1;
  }
  int ans = _tryCombination(S);
  for(int i = L; i <= R; i++) {
    if(D[i] != -1 && D[i] < lim) continue;
    S[i] ^= 1;
  }
  return ans;
}

void exploreCave(int N) {
  _N = N;

  int *S = new int[N];
  int *D = new int[N];
  for(int i = 0; i < N; i++) D[i] = -1;

  for(int i = 0; i < N; i++) {
    int curr = _tryCombination(S);
    assert(curr >= i);
    int L = 0, R = N - 1;
    while(L < R) {
      int mid = (L + R)/2;
      int test = flipCheck(S, D, i, L, mid);
      if((curr == i && test > i) || (curr > i && test == i)) {
        R = mid;
      }
      else {
        L = mid + 1;
      }
    }
    D[L] = i;
    if(curr == i) S[L] ^= 1;
  }

  answer(S, D);
}
