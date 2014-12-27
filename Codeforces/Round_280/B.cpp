// Vanya and Lanterns

#include <stdio.h>
#include <iostream>
#include <algorithm>

int main() {
  int N, L;
  scanf("%d %d", &N, &L);

  int lanterns[N];

  for(int i = 0; i < N; i++){
    scanf("%d", &lanterns[i]);
  }
  std::sort(lanterns, lanterns + N);

  double d_start = lanterns[0] - 0;
  double d_end = L - lanterns[N - 1];

  int max_diff = 0;
  for(int i = 0; i < N - 1; i++){
    if((lanterns[i+1] - lanterns[i]) > max_diff) max_diff = lanterns[i+1] - lanterns[i];
  }
  double d_mid = ((double)max_diff)/2.0;

  printf("%lf\n", std::max(std::max(d_start, d_end), d_mid));
}
