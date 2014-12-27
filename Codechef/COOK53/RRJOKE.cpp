// Good Joke!

#include <stdio.h>

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int N; scanf("%d", &N);
    int answer = 1;
    for(int i = 2; i <= N; i++){
      answer = answer ^ i;
    }
    while(N--){
      int x, y;
      scanf("%d %d", &x, &y);
    }

    printf("%d\n", answer);
  }
}
