// Stick Game

#include <stdio.h>
#include <algorithm>

int main(){
  int N;
  while(true){
    scanf("%d", &N);
    if(N == 0) break;
    int L[N];
    for(int i = 0; i < N; i++){
      scanf("%d", &L[i]);
    }
    std::sort(L, L + N);
    int count = 0;

    for(int i = 0; i < N - 2; i++){     // 2 5 6 9 13
      int k = i + 2;
      for(int j = i + 1; j < N; j++){
        while(k < N && L[i] + L[j] >= L[k]){
          k++;
        }

        count += N - k;
      }
    }

    printf("%d\n", count);
  }
}
