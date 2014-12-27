// Chef and Churu

#include <stdio.h>

typedef long long int BigInt;

BigInt calculateSum(BigInt* A, BigInt L, BigInt R){
  BigInt sum = 0;
  for(BigInt i = L; i <= R; i++){
    sum += A[i];
  }
  return sum;
}

int main(){
  int N; scanf("%d", &N);
  BigInt A[N+1], L[N+1], R[N+1], sums[N+1];
  int Q;
  int type, a, b;

  for(int i = 1; i <= N; i++) scanf("%llu", &A[i]);
  for(int i = 1; i <= N; i++) {
    scanf("%lli %lli", &L[i], &R[i]);
    sums[i] = calculateSum(A, L[i], R[i]);
  }

  scanf("%d", &Q);
  while(Q--){
    scanf("%d %d %d", &type, &a, &b);
    if(type == 1){
      BigInt diff = b - A[a];
      A[a] = b;
      for(int i = 1; i <= N; i++){
        if(L[i] <= a && a <= R[i]){
          sums[i] += diff;
        }
      }
    }
    else {
      printf("%lli\n", calculateSum(sums, a, b));
    }
  }
}
