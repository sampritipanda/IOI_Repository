// The last digit

#include <stdio.h>

int digits[10][4];

void precalc(){
  for(int i = 0; i < 10; i++){
    int result = 1;
    for(int j = 1; j <= 4; j++){
      result *= i;
      result %= 10;
      digits[i][j - 1] = result;
    }
  }
}

int main() {
  precalc();

  int T; scanf("%d", &T);

  while(T--){
    int a, b; scanf("%d %d", &a, &b);
    if(b == 0) printf("1\n");
    else printf("%d\n", digits[a % 10][(b - 1 + 4) % 4]);
  }
}
