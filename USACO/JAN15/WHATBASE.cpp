// It's All About the Base

#include <stdio.h>

using namespace std;

int find_N(int a, int b, int c, int B){
  return (B*B * a + B * b + c);
}

int main() {
  freopen("whatbase.in", "r", stdin);
  freopen("whatbase.out", "w", stdout);

  int K; scanf("%d", &K);

  while(K--){
    int N_X, N_Y; scanf("%d %d", &N_X, &N_Y);
    int c = N_X % 10;
    N_X /= 10;
    int b = N_X % 10;
    N_X /= 10;
    int a = N_X % 10;
    N_X /= 10;

    int f = N_Y % 10;
    N_Y /= 10;
    int e = N_Y % 10;
    N_Y /= 10;
    int d = N_Y % 10;
    N_Y /= 10;

    bool flag = false;
    for(int i = 10; i <= 15000; i++){
      for(int j = 10; j <= 15000; j++){
        if(i == j) continue;

        if(find_N(a, b, c, i) == find_N(d, e, f, j)) {
          printf("%d %d\n", i, j);
          flag = true;
          break;
        }
      }
      if(flag) break;
    }
  }

  fclose(stdin);
  fclose(stdout);
}
