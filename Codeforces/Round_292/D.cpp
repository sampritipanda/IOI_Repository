// Drazil and Tiles

#include <stdio.h>

using namespace std;

char grid[2000][2000];
char dp[2000][2000];
int n, m;

int main () {
  scanf("%d %d", &n, &m);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf(" %c", &grid[i][j]);
    }
  }
}
