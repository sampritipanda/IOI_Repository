#include <cstdio>
#include <algorithm>

using namespace std;

short A[1000000];

int main() {
  int N, K; scanf("%d %d", &N, &K);

  int sum = 0, i = 0;
  for(i = 0; i < K; i++) {
    scanf("%d", &A[i]);
    sum += A[i];
  }
  int ans = sum;

  for(; i < N; i++) {
    scanf("%d", &A[i]);
    sum += A[i];
    sum -= A[i - K];
    if(sum > ans) ans = sum;
  }

  printf("%d\n", ans);
}
