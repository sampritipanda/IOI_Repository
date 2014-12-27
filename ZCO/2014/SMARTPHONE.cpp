// Smart Phone

#include <stdio.h>
#include <algorithm>

int main(){
  int N; scanf("%d", &N);
  long long customers[N];

  for(int i = 0; i < N; i++) scanf("%lld", &customers[i]);
  std::sort(customers, customers + N);

  long long maxRevenue = 0;
  for(int i = 0; i < N; i++) {
    long long currRevenue = customers[i] * (N - i);
    if(currRevenue > maxRevenue) maxRevenue = currRevenue;
  }
  printf("%lld\n", maxRevenue);
}
