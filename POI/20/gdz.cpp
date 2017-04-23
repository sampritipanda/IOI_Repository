// gdz.cpp - Przykladowe użycie biblioteki do zadania GDZ
#include "cgdzlib.h"
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
  int N = inicjuj();
  if(N == 1) odpowiedz(1);

  int L = N/2, R = N - 1;
  int max_i = -1;
  while(L < R) {
    int mid = (L + R + 1)/2;
    bool exists = false;
    for(int i = 2; i <= N; i++) {
      if(f(1, i, mid)) {
        max_i = i;
        exists = true;
        break;
      }
    }

    if(exists) {
      L = mid;
    }
    else {
      R = mid - 1;
    }
  }
  int max_diff = L;

  if(g(1, max_i)) odpowiedz(max_i);
  else {
    for(int i = 1; i <= N; i++) {
      if(i != max_i && f(i, max_i, N - 1)) {
        odpowiedz(i);
      }
    }
  }

  return 0;
}
