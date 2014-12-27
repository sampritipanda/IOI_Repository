// Books - 279B

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int N, T; scanf("%d %d", &N, &T);
  int A[N], sums[N];

  for(int i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }

  sums[0] = A[0];
  for(int i = 1; i < N; i++) sums[i] = sums[i - 1] + A[i];

  int maxCount = 0;
  for(int i = 0; i < N; i++){
    int requiredSum = 0;
    if(i == 0) requiredSum = 0;
    else requiredSum = sums[i - 1];

    int length = upper_bound(sums, sums + N, T + requiredSum) - sums - i;
    if(length > maxCount) maxCount = length;
  }

  printf("%d\n", maxCount);
}
