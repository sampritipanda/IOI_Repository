// Longest Palindrome

#include <stdio.h>

int main() {
  int N = 0; scanf("%d", &N);
  char str[5001]; scanf("%s", str);

  int maxLength = 1, start = 0;
  int low, high;

  for(int i = 1; i < N; i++){
    low = i - 1;
    high = i;

    while(low >= 0 && high < N && str[low] == str[high]){
      if(high - low + 1 > maxLength){
        start = low;
        maxLength = high - low + 1;
      }
      low--;
      high++;
    }

    low = i - 1;
    high = i + 1;

    while(low >= 0 && high <= N && str[low] == str[high]){
      if(high - low + 1 > maxLength){
        start = low;
        maxLength = high - low + 1;
      }
      low--;
      high++;
    }
  }

  printf("%d\n", maxLength);
  for(int i = start; i < start + maxLength; i++) printf("%c", str[i]);
  printf("\n");
}
