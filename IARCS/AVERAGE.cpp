// Average

#include <stdio.h>
#include <algorithm>

using namespace std;

int A[10000];

int main() {
  int N; scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%d", A + i);

  sort(A, A + N);

  int ans = 0;
  for(int k = 0; k < N; k++) {
    int i = 0, j = N - 1;
    int sum = 2*A[k];
    while(i < j) {
      if(A[i] + A[j] < sum) {
        i++;
      }
      else if(A[i] + A[j] > sum) {
        j--;
      }
      else {
        ans++;
        break;
      }
    }
  }

  printf("%d\n", ans);
}
