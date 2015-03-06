// Twins

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int N; scanf("%d", &N);
  int A[N], sums[N];

  for(int i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  sort(A, A + N);

  sums[0] = A[0];
  for(int i = 1; i < N; i++) sums[i] = sums[i - 1] + A[i];

  int i;
  for(i = N - 1; i >= 0; i--){
    if((sums[N - 1] - sums[i - 1]) > sums[i - 1]) break;
  }

  printf("%d\n", N - i);
}
