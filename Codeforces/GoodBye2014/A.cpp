// New Year Transportation

#include <stdio.h>

int main() {
  int N, t; scanf("%d %d", &N, &t);
  int A[N + 1];

  for(int i = 1; i < N; i++) scanf("%d", &A[i]);

  int i = 1;
  bool flag = false;
  while(i <= N){
    if(i == t) {
      flag = true;
      break;
    }
    i += A[i];
  }

  if(flag) printf("YES\n");
  else printf("NO\n");
}
