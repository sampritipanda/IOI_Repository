// Servers

#include <stdio.h>
#include <cmath>
#include <limits.h>

using namespace std;

int main() {
  int N, M; scanf("%d %d", &N, &M);
  int graph[N + 1][N + 1];
  bool exists[N + 1][N + 1];

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      graph[i][j] = abs(i - j);
      graph[j][i] = abs(i - j);
    }
  }

  int distance = 0;
  int pairs[M][2];
  for(int i = 0; i < M; i++){
    scanf("%d %d", &pairs[i][0], &pairs[i][1]);
    if(abs(pairs[i][0] - pairs[i][1]) == 1){
      distance++;
      exists[pairs[i][0]][pairs[i][1]] = true;
      exists[pairs[i][1]][pairs[i][0]] = true;
    }
  }

  for(int i = 0; i < M; i++){
    int src = pairs[i][0];
    int dest = pairs[i][1];
    if(abs(src - dest) > 1){
    }
  }
}

