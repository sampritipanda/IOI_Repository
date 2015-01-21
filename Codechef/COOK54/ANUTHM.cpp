// Tojo hates probabilities

#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int N, M; scanf("%d %d", &N, &M);
    printf("%lf\n", N*1.0 + M*1.0 - 1.0);
  }
}
