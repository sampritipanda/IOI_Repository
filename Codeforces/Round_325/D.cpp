#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

string grid[3];
bool visited[100][3][301];
vector<pair<pair<int, int>, int> > trains;

bool check(int i, int j, int time) {
  for(auto train: trains) {
    int m = train.first.first - 2*time, n = train.first.second - 2*time, o = train.second;

    if(o != j) continue;
    if(m < 0 && n < 0) continue;
    else {
      if(m < 0) m = 0;
      if(i >= m && i <= n) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int T; cin >> T;

  while(T--) {
    trains.clear();
    grid[0] = grid[1] = grid[2] = "";
    int N, K; cin >> N >> K;

    cin >> grid[0] >> grid[1] >> grid[2];

    int x, y;

    for(int j = 0; j < 3; j++) {
      for(int i = 0; i < N; i++) {
        if(grid[j][i] == 's') {
          x = i, y = j;
        }
        else if(grid[j][i] >= 'A' && grid[j][i] <= 'Z') {
          int k;
          for(k = i; grid[j][k] == grid[j][i]; k++) {}
          k--;
          trains.push_back({{i, k}, j});
          i = k;
        }
      }
    }

    bool possible = false;
    memset(visited, false, sizeof visited);
    queue<pair<pair<int, int>, int> > Q;
    Q.push({{x, y}, 0});

    while(!Q.empty()) {
      auto curr = Q.front();
      Q.pop();
      int i = curr.first.first, j = curr.first.second, time = curr.second;

      if(visited[i][j][time]) continue;
      visited[i][j][time] = true;

      if(!check(i, j, time)) continue;

      cout << i << " " << j << " " << time << endl;

      if(i == N - 1) {
        possible = true;
        break;
      }

      if(j > 0) Q.push({{i + 1, j - 1}, time + 1});
      if(j < 2) Q.push({{i + 1, j + 1}, time + 1});
      Q.push({{i + 1, j}, time + 1});
    }

    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
