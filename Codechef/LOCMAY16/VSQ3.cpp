#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int A[100001];

int main() {
  int T; scanf("%d", &T);

  while(T--) {
    int N, Q1, Q2, Q3, Q4; scanf("%d %d %d %d %d", &N, &Q1, &Q2, &Q3, &Q4);

    for(int i = 1; i <= N; i++) {
      scanf("%d", &A[i]);
    }

    bool pos = false;
    for(int i = 1; i <= N; i++) {
      if(A[i] != Q1 && A[i] != Q2 && A[i] != Q3 && A[i] != Q4) pos = true;
    }

    if(pos) {
      long long curr = 0;
      long long ans = LLONG_MIN/2;
      int i = 1;
      while(i <= N) {
        if(A[i] == Q1 || A[i] == Q2 || A[i] == Q3 || A[i] == Q4) {
          curr = 0;
          i++;
          continue;
        }
        curr = max((long long)A[i], curr + A[i]);
        ans = max(ans, curr);
        i++;
      }
      printf("%lld\n", ans);
    }
    else printf("0\n");
  }
}
