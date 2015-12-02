#include <stdio.h>

#define MAX_N 10000000

using namespace std;

bool prime[10000001];
int phi[10000001];
long long ans[10000001];

int main() {
  prime[0] = prime[1] = false;
  for(int i = 2; i <= MAX_N; i++) prime[i] = true;
  phi[0] = 0;
  for(int i = 1; i <= MAX_N; i++) phi[i] = i;
  for(int i = 0; i <= MAX_N; i++) ans[i] = 0;

  for(int i = 2; i <= MAX_N; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= MAX_N; j += i) {
      prime[j] = false;
    }
  }

  for(int i = 1; i <= MAX_N; i++) {
    if(prime[i]) {
      for(int j = i; j <= MAX_N; j += i) {
        phi[j] -= phi[j]/i;
      }
    }
  }

  for(long long i = 1; i <= MAX_N; i++) {
    long long curr = i * phi[i];
    for(int j = i; j <= MAX_N; j += i) {
      ans[j] += curr;
    }
  }

  int T; scanf("%d", &T);

  while(T--) {
    int N; scanf("%d", &N);
    printf("%lld\n", ans[N]);
  }
}

