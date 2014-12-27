// Random Ram

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int T; scanf("%d", &T);
  long M;
  char int_str[21];

  while(T--){
    int count = 1;
    scanf("%lu", &M);
    sprintf(int_str, "%lu", M);
    int length = strlen(int_str);

    for(int i = 0; i < length - 1; i++){
      const char curr_str[] = { int_str[i], int_str[i + 1] };
      int curr = atoi(curr_str);
      if(curr >= 10 && curr <= 26) count++;
    }
    if(length > 4){
      for(int i = 0; i < length - 2; i += 2){
        const char curr_str[] = { int_str[i], int_str[i + 1] };
        int curr = atoi(curr_str);
        if(curr >= 10 && curr <= 26) count++;
      }
    }
    printf("%d\n", count);
  }
}
