// Around the world

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

int A[1000000];

int main() {
  int N, S; scanf("%d %d", &N, &S);

  for(int i = 0; i < N; i++) scanf("%d", &A[i]);

  while(S--) {
    int D; scanf("%d", &D);

    bool pos = true;
    for(int i = 0; i < N; i++) {
      if(A[i] > D) pos = false;
    }
    if(!pos) {
      printf("NIE\n");
      continue;
    }

    int ans = N + 1;

    int L = 0, R = N + 1;
    int i = 0;
    while(true) {
      int start = i;
      int sum = 0;
      while(true) {
        if(sum + A[i] <= D) {
          sum += A[i];
          i = (i + 1) % N;
        }
        else break;

        if(i == 0) {
          i = N;
          break;
        }
      }
      if((i - start) < (R - L)) {
        L = start;
        R = i;
      }
      if(i == N) break;
    }

    for(int start = L; start < R; start++) {
      int i = start;
      int curr = 0;
      while(true) {
        int sum = 0;
        while(true) {
          if(sum + A[i] <= D) {
            sum += A[i];
            i = (i + 1) % N;
          }
          else break;

          if(i == start) break;
        }
        curr++;
        if(i == start) break;
      }
      if(ans == N + 1) ans = curr;
      else if(curr < ans) {
        ans = curr;
        break;
      }
    }

    printf("%d\n", ans);
  }
}
