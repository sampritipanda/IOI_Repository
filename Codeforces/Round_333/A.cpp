#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int A[401][401], B[401][401];
bool visited[401][401];
// A = Railway Graph
// B = Roadway Graph

int main() {
  int N, M; cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      A[i][j] = 0;
      B[i][j] = 1;
      visited[i][j] = false;
    }
  }

  while(M--) {
    int i, j; cin >> i >> j;
    A[i][j] = 1; A[j][i] = 1;
    B[i][j] = 0; B[j][i] = 0;
  }

  for(int i = 1; i <= N; i++) A[i][i] = B[i][i] = 0;

  queue<pair<pair<int, int>, int> > Q;
  Q.push({{1, 1}, 0});
  visited[1][1] = true;

  int ans = -1;
  while(!Q.empty()) {
    auto it = Q.front();
    Q.pop();
    int i = it.first.first, j = it.first.second, t = it.second;

    if(i == N && j == N) {
      ans = t; break;
    }

    if(i == N) {
      for(int x = 1; x <= N; x++) {
        if(B[j][x]) {
          if(!visited[i][x]) {
            Q.push({{i, x}, t + 1});
            visited[i][x] = true;
          }
        }
      }
    }
    else if(j == N) {
      for(int x = 1; x <= N; x++) {
        if(A[i][x]) {
          if(!visited[x][j]) {
            Q.push({{x, j}, t + 1});
            visited[x][j] = true;
          }
        }

      }
    }
    else {
      for(int x = 1; x <= N; x++) {
        if(A[i][x]) {
          for(int y = 1; y <= N; y++) {
            if(B[j][y]) {
              if(x != y || x == N) {
                if(!visited[x][y]) {
                  Q.push({{x, y}, t + 1});
                  visited[x][y] = true;
                }
              }
            }
          }
        }
      }
    }
  }

  cout << ans << endl;
}

