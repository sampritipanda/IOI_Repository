// Rupsa and Equilateral Triangle

#include <cstdio>
#include <algorithm>

using namespace std;

bool sieve[5000001], mark[5000001];

int main() {
  for(int i = 1; i <= 5000000; i++) {
    sieve[i] = true;
    mark[i] = false;
  }

  for(int i = 2; i <= 5000000; i++) {
    if(!sieve[i]) continue;

    for(int j = i + i; j <= 5000000; j += i) {
      sieve[j] = false;
    }

    if(i % 4 != 1) sieve[i] = false;
  }

  for(int i = 2; i <= 5000000; i++) {
    if(!sieve[i]) continue;

    for(int j = i; j <= 5000000; j += i) mark[j] = true;
  }

  int T; scanf("%d", &T);

  while(T--) {
    int N; scanf("%d", &N);
    if(mark[N]) printf("YES\n");
    else printf("NO\n");
  }
}
