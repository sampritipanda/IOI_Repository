// Around the world

#include <cstdio>
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

    int ans = N;

    for(int start = 0; start < N; start++) {
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
      ans = min(ans, curr);
    }

    printf("%d\n", ans);
  }
}
