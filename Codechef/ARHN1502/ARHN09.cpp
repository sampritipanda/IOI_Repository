// Queries

#include <stdio.h>
#include <string>

int main() {
  int N, Q; scanf("%d %d", &N, &Q);
  long long sum[N + 1];
  sum[0] = 0;

  for(int i = 1; i <= N; i++){
    int x; scanf("%d", &x);
    sum[i] = sum[i - 1] + x;
  }

  for(int i = 0; i < Q; i++){
    char temp[100]; scanf("%s", temp);
    int x, y; scanf(" %d %d", &x, &y);
    printf("%lld\n", sum[y] - sum[x - 1]);
  }
}
