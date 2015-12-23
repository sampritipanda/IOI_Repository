#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>

using namespace std;

// #define in cin
// #define out cout

int A[1001][1001];
bool visited[1001][1001][2][4];

int main() {
  ifstream in("dream.in");
  ofstream out("dream.out");

  int N, M; in >> N >> M;

  memset(visited, false, sizeof visited);

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      in >> A[i][j];
    }
  }

  // {x, y, orange?, direction, ans}
  // direction => 0 = up, 1 = right, 2 = down, 3 = left
  queue<vector<int> > Q;
  Q.push({1, 1, 0, -1, 0});
  int ans = -1;

  while(!Q.empty()) {
    auto curr = Q.front(); Q.pop();
    int x = curr[0], y = curr[1], orange = curr[2], direction = curr[3], moves = curr[4];

    if(x < 1 || x > N || y < 1 || y > M) continue;
    if(A[x][y] == 0) continue;
    if(A[x][y] == 3 && !orange) continue;
    if(visited[x][y][orange][direction]) continue;
    visited[x][y][orange][direction] = true;

    if(x == N && y == M) {
      if(ans == -1) ans = moves;
      else ans = min(ans, moves);
      continue;
    }

    if(A[x][y] == 4) {
      orange = 0;

      int nX = x, nY = y;
      if(direction == 0) { // Up
        nX--;
      }
      else if(direction == 1) { // Right
        nY++;
      }
      else if(direction == 2) { // Down
        nX++;
      }
      else{  // Left
        nY--;
      }

      if(nX < 1 || nX > N || nY < 1 || nY > M || A[nX][nY] == 0 || A[nX][nY] == 3) {
        Q.push({x - 1, y, orange, 0, moves + 1});
        Q.push({x, y + 1, orange, 1, moves + 1});
        Q.push({x + 1, y, orange, 2, moves + 1});
        Q.push({x, y - 1, orange, 3, moves + 1});
      }
      else {
        Q.push({nX, nY, orange, direction, moves + 1});
      }
    }
    else {
      if(A[x][y] == 2) orange = 1;

      Q.push({x - 1, y, orange, 0, moves + 1});
      Q.push({x, y + 1, orange, 1, moves + 1});
      Q.push({x + 1, y, orange, 2, moves + 1});
      Q.push({x, y - 1, orange, 3, moves + 1});
    }
  }

  out << ans << endl;
}
