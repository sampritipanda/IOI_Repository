// Chef and A Large Permutation

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int T; scanf("%d", &T);

  while(T--){
    unsigned long long N, K; scanf("%llu %llu", &N, &K);
    int missing[K];
    bool missing_1 = false, missing_2 = false;

    for(int i = 0; i < K; i++){
      scanf("%d", &missing[i]);
      if(missing[i] == 1) missing_1 = true;
      else if(missing[i] == 2) missing_2 = true;
    }

    if(missing_1){
      printf("Chef\n");
    }
    else if((N == 1 && K == 0) || missing_2){
      printf("Mom\n");
    }
    else {
      sort(missing, missing + K);
      unsigned long long res = 1, i = 1, j = 0;

      while(i <= N && i <= res){
        unsigned long long end;
        if(j == K) end = N;
        else end = missing[j] - 1;

        res += ((end + 1) * end)/2 - ((i - 1) * i)/2;
        i = end + 1;
        while(j < K && missing[j] == i){
          i++;
          j++;
        }
      }

      if(res % 2 == 0) printf("Mom\n");
      else printf("Chef\n");

      // printf("%llu\n", res);
    }
  }
}
