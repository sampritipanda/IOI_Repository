// Dollar Game

#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
  long long X; scanf("%lld", &X);
  char seq[1010]; scanf(" %s", seq);
  int len = strlen(seq);

  for(int i = 0; i < len; i++){
    if(seq[i] == 'W') X = X*2 + 11;
    else {
      if(X % 2 == 0) X /= 2;
      else X = X/2 + 1;
    }
  }

  printf("%lld\n", X);
}
