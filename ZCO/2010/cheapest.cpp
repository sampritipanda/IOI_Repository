// Cheapest path in a grid

#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>

using std::make_pair;

#define pii std::pair<int, int>

int distance[1000][1000];

inline int abs(int a){
  if(a < 0) return -a;
  else return a;
}

struct comp {
  bool operator() (const pii& lhs, const pii& rhs) const {
    return distance[lhs.first][lhs.second] < distance[rhs.first][rhs.second];
  }
};

int main(){
  int N, K;
  scanf("%d %d", &N, &K);
  K--;

  int grid[N][N];
  std::priority_queue<pii, std::vector<pii>, comp> queue;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      scanf("%d", &grid[i][j]);
      distance[i][j] = 2147483647;
    }
  }
  distance[0][0] = grid[0][0];
  queue.push(make_pair(0, 0));

  while(!queue.empty()){
    pii curr = queue.top();
    queue.pop();
    int i = curr.first, j = curr.second;

    if(j == K - 1){
      for(int m = 0; m < N; m++){
        int new_distance = distance[i][j] + grid[m][j + 1] + abs(i - m);
        if(new_distance < distance[m][j + 1]){
          distance[m][j + 1] = new_distance;
          queue.push(make_pair(m, j + 1));
        }
      }
    }
    else {
      if(j < N - 1){
        int new_distance = distance[i][j] + grid[i][j + 1];
        if(new_distance < distance[i][j + 1]){
          distance[i][j+1] = new_distance;
          queue.push(make_pair(i, j + 1));
        }
      }
    }

    if(i < N - 1){
      int new_distance = distance[i][j] + grid[i + 1][j];
      if(new_distance < distance[i + 1][j]){
        distance[i+1][j] = new_distance;
          queue.push(make_pair(i + 1, j));
      }
    }
  }

  printf("%d\n", distance[N-1][N-1]);
}
