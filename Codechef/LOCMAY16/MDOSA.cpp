#include <cstdio>

using namespace std;

int main() {
  int T; scanf("%d", &T);

  while(T--) {
    long long N; scanf("%lld", &N);

    if(N % 2 == 1 || N == 2) printf("NO\n");
    else printf("YES\n");
  }
}
