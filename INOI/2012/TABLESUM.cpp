// Table Sum

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int N; scanf("%d", &N);
  int A[N + 2];

  A[0] = A[N + 1] = 0;

  for(int i = 1; i <= N; i++){
    scanf("%d", &A[i]);
    A[i] += i;
    A[i] = max(A[i], A[i - 1]);
  }

  printf("%d ", A[N]);

  for(int i = N; i > 1; i--){
    A[i] -= N;
    A[i] = max(A[i], A[i + 1]) + 1;
    A[i - 1] += N - i + 1;

    printf("%d ", max(A[i], A[i - 1]));
  }

  printf("\n");
}
