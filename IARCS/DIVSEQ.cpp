// Dividing Sequences

#include <stdio.h>

int main(){
  int N; scanf("%d", &N);

  int arr[N], dp[N];
  int maxLength = N & 1;

  for(int i = 0; i < N; i++){
    scanf("%d", &arr[i]);
    dp[i] = 1;
  }

  for(int i = 1; i < N; i++){
    for(int j = 0; j < i; j++){
      if(arr[i] % arr[j] == 0 && dp[i] < dp[j] + 1){
        dp[i] = dp[j] + 1;
        if(dp[i] > maxLength) maxLength = dp[i];
      }
    }
  }

  printf("%d\n", maxLength);
}
