// False Fibonacci Series

#include <stdio.h>

int main() {
  unsigned long long* series = new unsigned long long[100000001];

  series[0] = 2;
  series[1] = 5;

  for(int i = 2; i <= 100000000; i++){
    series[i] = 2*series[i - 1] + 3*series[i - 2];
    series[i] %= 1000000007;
  }

  int T; scanf("%d", &T);
  while(T--){
    int N; scanf("%d", &N);
    printf("%llu\n", series[N]);
  }
}
