// Candy I

#include <stdio.h>

int main() {
  int N;
  while(true){
    scanf("%d", &N);
    if(N == -1) break;

    int candies[N];
    int average = 0;
    for(int i = 0; i < N; i++){
      scanf("%d", &candies[i]);
      average += candies[i];
    }

    if(average % N != 0) printf("-1\n");
    else {
      average /= N;
      int more = 0, less = 0;
      for(int i = 0; i < N; i++) {
        int currStat = average - candies[i];
        if(currStat >= 0) less += currStat;
        else more += -currStat;
      }

      if(more != less) printf("-1\n");
      else printf("%d\n", more);
    }
  }
}
