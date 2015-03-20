// Matrix

#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

int N, M;
int grid[1000055];
int sizes[1000055];
int max_size = 0, max_size_color = 0;

// Each number is a 4 length bitset: <Up><Right><Down><Left> (3210)
int wall[1015][1015];

struct query {
  int type;
  int x, y;
  int x1, y1, x2, y2;
  bool duplicate;
};

query queries[1000055];

int find_group(int x) {
  if (x == grid[x]) return x;
  return grid[x] = find_group(grid[x]);
}

void merge_group(int a, int b) {
  a = find_group(a);
  b = find_group(b);
  if (a != b) {
    grid[a] = b;
    sizes[b] += sizes[a];
    sizes[a] = 0;
    if(sizes[b] > max_size){
      max_size = sizes[b];
      max_size_color = b;
    }
  }
}

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int Q_count; scanf("%d %d %d", &N, &M, &Q_count);
    for(int i = 0; i <= (N + 5); i++){
      for(int j = 0; j <= (M + 5); j++){
        wall[i][j] = 0;
      }
    }
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        grid[i*M + j] = i*M + j;
        sizes[i*M + j] = 1;
      }
    }
    max_size = 1, max_size_color = 0;

    for(int i = 0; i < Q_count; i++){
      int type; scanf("%d", &type);
      queries[i].type = type;
      queries[i].duplicate = false;

      if(type == 1) {
        int x, y; scanf("%d %d", &x, &y);
        x--; y--;
        queries[i].x = x; queries[i].y = y;
        if(wall[x][y] & (1 << 2)) queries[i].duplicate = true;
        wall[x][y] |= (1 << 2);
        wall[x + 1][y] |= (1 << 0);
      }
      else if(type == 2){
        int x, y; scanf("%d %d", &x, &y);
        x--; y--;
        queries[i].x = x; queries[i].y = y;
        if(wall[x][y] & (1 << 1)) queries[i].duplicate = true;
        wall[x][y] |= (1 << 1);
        wall[x + 1][y] |= (1 << 3);
      }
      else if(type == 3){
        int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1--; y1--; x2--; y2--;
        queries[i].x1 = x1; queries[i].y1 = y1; queries[i].x2 = x2; queries[i].y2 = y2;
      }
      else {
      }
    }

    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++){
        if(i < (N - 1) && (wall[i][j] & (1 << 1)) == 0) merge_group(i*M + j, (i+1)*M + j);
        if(j < (M - 1) && (wall[i][j] & (1 << 2)) == 0) merge_group(i*M + j, i*M + j+1);
      }
    }

    long long sum = 0;
    for(int i = Q_count - 1; i >= 0; i--){
      query q = queries[i];
      if(q.duplicate) continue;
      if(q.type == 1){
        int x = q.x, y = q.y;
        merge_group(x*M + y, x*M + y+1);
      }
      else if(q.type == 2){
        int x = q.x, y = q.y;
        merge_group(x*M + y, (x+1)*M + y);
      }
      else if(q.type == 3){
        sum += (find_group(q.x1*M + q.y1) == find_group(q.x2*M + q.y2) ? 1 : 0);
      }
      else {
        sum += max_size;
      }
    }

    printf("%lld\n", sum);
  }
}
