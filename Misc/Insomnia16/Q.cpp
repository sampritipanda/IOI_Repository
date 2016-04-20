#include <cstdio>

using namespace std;

int main() {
  int T; scanf("%d", &T);

  while(T--) {
    int N; scanf("%d", &N);
    int ans = 0;

    for(int i = 1; i*i <= N; i++) {
      if(N % i == 0) {
        ans++;
        if(i != N/i) ans++;
      }
    }

    printf("%d\n", ans);
  }
}
