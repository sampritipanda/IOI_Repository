// Will India Win

#include <stdio.h>

int countSetBits(int n) {
    int count = 0;
    while (n) {
      n &= (n-1);
      count++;
    }
    return count;
}

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int val = 0;
    for(int i = 0; i < 15; i++){
      int a; scanf("%d", &a);
      val ^= a;
    }

    int X; scanf("%d", &X);
    if(countSetBits(val) > X) printf("YES\n");
    else printf("NO\n");
  }
}
