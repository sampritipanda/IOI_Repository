// Alok-nath and His Sanskars

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T; scanf("%d", &T);
  int N, K;

  while(T--){
    scanf("%d %d", &N, &K);
    vector<long long> sanskars;
    long long sanskarSum = 0;

    for(int i = 0; i < N; i++){
      long long sanskar;
      scanf("%lld", &sanskar);
      sanskarSum += sanskar;
      sanskars.push_back(sanskar);
    }

    bool flag = true;
    long long average = sanskarSum / K;
    for(int i = 0; i < N; i++){
      if(sanskars[i] > average) {
        flag = false;
        break;
      }
    }

    if(sanskarSum % K != 0) printf("no\n");
    else if(K == 1) printf("yes\n");
    else if(!flag) printf("no\n");
    else {
      while(!sanskars.empty()){
        int len = sanskars.size();
        long long i;
        for(i = 0; i < (1LL << len); i++){
          long long sum = 0;
          vector<int> positions;
          // printf("%lld: {", i);
          for(long long k = 0; k < len; k++){
            if((i & (1LL << k)) > 0) {
              sum += sanskars[k];
              positions.push_back(k);
              // printf("%lld ", sanskars[k]);
            }
          }
          // printf("} : %lld\n", sum);
          if(sum == average){
            K--;
            int len2 = positions.size();
            for(int a = 0; a < len2; a++){
              // printf("Deleted at index %d: %lld\n", positions[a], *(sanskars.begin() + positions[a]));
              sanskars.erase(sanskars.begin() + (positions[a] - a));
            }
            break;
          }
        }
        if(i == (1LL << len)) break;
      }

      if(K == 0){
        printf("yes\n");
      }
      else {
        printf("no\n");
      }
    }
    // printf("\n\n\n");
  }
}
