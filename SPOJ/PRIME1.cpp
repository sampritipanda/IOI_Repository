// Prime Generator

#include <stdio.h>

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int m, n; scanf("%d %d", &m, &n);

    for(int i = m; i <= n; i++){
      if(i == 1) continue;
      bool prime = true;
      for(int j = 2; j*j <= i; j++){
        if(i % j == 0) {
          prime = false;
          break;
        }
      }
      if(prime || i == 2) printf("%d\n", i);
    }
    printf("\n");
  }
}
