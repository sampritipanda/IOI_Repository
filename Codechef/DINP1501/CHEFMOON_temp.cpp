// Chef and moon

#include <stdio.h>
#include <vector>

using namespace std;

int main() {
  int N, M, K; scanf("%d %d %d", &N, &M, &K);
  unsigned long long dist[N + 1][N + 1];

  for(int i = 1; i <= N; i++){
    dist[i][i] = 0;
    for(int j = 1; j <= N; j++){
      dist[i][j] = -1;
    }
  }
  for(int i = 0; i < M; i++){
    int A, B, C; scanf("%d %d %d", &A, &B, &C);
    dist[A][B] = C;
    dist[B][A] = C;
  }

  for(int k = 1; k <= N; k++){
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int Q; scanf("%d", &Q);

  for(int i = 0; i < Q; i++){
    int U, V; scanf("%d %d", &U, &V);
    if(dist[U][V] <= K) printf("YES\n");
    else printf("NO\n");
  }
}
