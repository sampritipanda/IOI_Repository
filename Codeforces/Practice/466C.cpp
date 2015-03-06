// Number of Ways

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  int N; scanf("%d", &N);
  int A[N];
  long long totalSum = 0;

  for(int i = 0; i < N; i++){
    scanf("%d", &A[i]);
    totalSum += A[i];
  }

  if(N < 3 || totalSum % 3 != 0) printf("0\n");
  else {
    long long eachSum = totalSum/3;
    long long sum = 0;
    int cnt[N];

    for(int i = N - 1; i > 0; i--){
      sum += A[i];
      if(sum == eachSum) cnt[i] = 1;
      else cnt[i] = 0;

      if(i < (N - 1)) cnt[i] += cnt[i + 1];
    }

    long long count = 0;
    sum = 0;
    for(int i = 0; i < N - 2; i++){
      sum += A[i];
      if(sum == eachSum) count += cnt[i + 2];
    }

    cout << count << endl;
  }
}
