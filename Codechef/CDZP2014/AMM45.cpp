// A Million Miles

#include <stdio.h>
#include <cmath>
#include <queue>
#include <map>
#include <utility>

double distance_points(std::pair<int, int> start, std::pair<int, int> end) {
  double dx = (end.first-start.first);
  double dy = (end.second-start.second);
  double dist = dx*dx + dy*dy;
  return dist;
}

int bfs(int start_x, int start_y, int end_x, int end_y){
  int count = 0;
  std::pair<int, int> start, end;
  start = std::make_pair(start_x, start_y);
  end = std::make_pair(end_x, end_y);

  std::pair<int, int> neighbour_top, neighbour_right, neighbour_down;

  std::queue<std::pair<int, int> > queue;
  std::map<std::pair<int, int>, bool > visited;

  visited[start] = true;
  queue.push(start);

  while(!queue.empty()){
    std::pair<int, int> curr = queue.front();
    // printf("%d %d\n", curr.first, curr.second);
    queue.pop();

    if(curr == end) count++;

    std::pair<int, int> neighbours[] = { std::make_pair(curr.first, curr.second + 1), std::make_pair(curr.first + 1, curr.second), std::make_pair(curr.first, curr.second - 1) };

    for(int i = 0; i < 3; i++){
      if(neighbours[i].second <= neighbours[i].first && distance_points(neighbours[i], end) <= distance_points(curr, end)){
        // printf("%d %d\n", neighbours[i].first, neighbours[i].second);
        visited[neighbours[i]] = true;
        queue.push(neighbours[i]);
      }
    }
    // printf("\n");
  }

  return count;
}

int main(){
  int T; scanf("%d", &T);
  int start_x, start_y, end_x, end_y;

  while(T--){
    scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);
    printf("%d\n", bfs(start_x, start_y, end_x, end_y));
  }
}
