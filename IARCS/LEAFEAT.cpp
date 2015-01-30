// The Leaf Eaters

#include <stdio.h>

long long gcd(long long a, long long b) {
  if(b == 0) return a;
  else return gcd(b, a % b);
}

long long recur(int *arr, int len, int i, long long cumul, long long bound) {
    if (bound == 0) {
        return bound;
    }
    long long g = arr[i]/gcd(cumul, arr[i]);
    long long result = bound/g;
    for(long long j = i + 1; j < len; j++) {
        result -= recur(arr, len, j, cumul*g, bound/g);
    }
    return result;
}

int main() {
  int N, K; scanf("%d %d", &N, &K);
  int A[K];
  for(int i = 0; i < K; i++) scanf("%d", &A[i]);

  long long count = N - 1;
  for(int i = 0; i < K; i++){
    count -= recur(A, K, i, 1, N - 1);
  }

  printf("%lld\n", count);
}
