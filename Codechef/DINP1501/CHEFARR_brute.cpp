// Chef and array

#include <stdio.h>

long long range_sum(long long sum[], int i, int j){
  if(i == 0) return sum[j];
  else return sum[j] - sum[i - 1];
}

int main() {
  int N; scanf("%d", &N);

  long long A[N], sum[N];

  for(int i = 0; i < N; i++) scanf("%lld", &A[i]);
  sum[0] = A[0];
  for(int i = 1; i < N; i++) sum[i] = sum[i - 1] + A[i];

  if(sum[N - 1] % 3 != 0) printf("0\n");
  else if(N == 3){
    if(A[0] == A[1] && A[1] == A[2]) printf("1\n");
    else printf("0\n");
  }
  else {
    long long each_sum = sum[N - 1]/3;
    long long count = 0;

    for(int i = 0; i < N - 2; i++){
      for(int j = N - 1; j >= 2; j--){
        if(i != j && range_sum(sum, 0, i) == each_sum && range_sum(sum, i + 1, j - 1) == each_sum && range_sum(sum, j, N - 1) == each_sum){
          count++;
        }
      }
    }

    printf("%lld\n", count);
  }
}
