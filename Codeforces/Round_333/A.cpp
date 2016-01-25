#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int A[401][401], B[401][401];
bool visited[401];
// A = Railway Graph
// B = Roadway Graph

int main() {
  int N, M; cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      A[i][j] = 0;
      B[i][j] = 1;
      visited[i] = false;
    }
  }

  while(M--) {
    int i, j; cin >> i >> j;
    A[i][j] = 1; A[j][i] = 1;
    B[i][j] = 0; B[j][i] = 0;
  }

  for(int i = 1; i <= N; i++) A[i][i] = B[i][i] = 0;

  queue<pair<int, int> > Q;
  Q.push({1, 0});
  int type = (A[1][N] == 1 ? 2 : 1); // 1 = Bus, 2 = Train

  int ans = -1;
  while(!Q.empty()) {
    auto it = Q.front();
    Q.pop();
    int i = it.first, t = it.second;

    if(i == N) {
      ans = t; break;
    }

    if(visited[i]) continue;
    visited[i] = true;

    for(int j = 1; j <= N; j++) {
      if(type == 1) {
        if(A[i][j]) Q.push({j, t + 1});
      }
      else {
        if(B[i][j]) Q.push({j, t + 1});
      }
    }
  }

  cout << ans << endl;
}

