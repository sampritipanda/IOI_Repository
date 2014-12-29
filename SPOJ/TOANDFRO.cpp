// To and Fro

#include <stdio.h>
#include <string.h>

int main() {
  int N;
  char str[500];

  while(true) {
    scanf(" %d", &N);
    if(N == 0) break;

    scanf("%s", str);
    int len = strlen(str);

    for(int i = 1; i <= N; i++){
      for(int j = 0; j < (len/N); j++){
        if(j % 2 == 0){
          printf("%c", str[i + j*N - 1]);
        }
        else {
          printf("%c", str[(j+1)*N - (i - 1) - 1]);
        }
      }
    }

    printf("\n");
  }
}
