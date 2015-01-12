// Fashion Shows

#include <stdio.h>
#include <algorithm>
#include <functional>

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int N; scanf("%d", &N);
    int men[N], women[N];

    for(int i = 0; i < N; i++) scanf("%d", &men[i]);
    for(int i = 0; i < N; i++) scanf("%d", &women[i]);

    std::sort(men, men + N, std::greater<int>());
    std::sort(women, women + N, std::greater<int>());

    int sum = 0;
    for(int i = 0; i < N; i++){
      sum += men[i] * women[i];
    }

    printf("%d\n", sum);
  }
}
