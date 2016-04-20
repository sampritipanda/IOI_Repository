#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

char A[1001][1001];
bool vis[1001][1001];
int D[4][1001][1001];
int N, M;

// i = start country, j = end country
int bfs(int x, int y) {
  memset(vis, false, sizeof vis);
  queue<vector<int> > Q;  // {x, y, dist}

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      D[x][i][j] = N * M * 10;
      if(A[i][j] == char(x + '0')) {
        Q.push({i, j, 0});
      }
    }
  }

  int ans = N * M * 10;

  while(!Q.empty()) {
    int i = Q.front()[0], j = Q.front()[1], d = Q.front()[2];
    Q.pop();

    if(i < 1 || i > N || j < 1 || j > M) continue;

    if(vis[i][j]) continue;
    vis[i][j] = true;

    D[x][i][j] = min(D[x][i][j], d + (A[i][j] == '.' ? 1 : 0));

    if(A[i][j] == '#') continue;
    if(A[i][j] == char(y + '0')) ans = min(ans, d);

    int new_d = (A[i][j] == '.' ? d + 1 : d);

    Q.push({i + 1, j, new_d});
    Q.push({i - 1, j, new_d});
    Q.push({i, j + 1, new_d});
    Q.push({i, j - 1, new_d});
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> M;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> A[i][j];
    }
  }

  int d_12 = bfs(1, 2);
  int d_13 = bfs(3, 1);
  int d_23 = bfs(2, 3);
  int ans = min({d_12 + d_13, d_12 + d_23, d_13 + d_23});

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(A[i][j] == '.') {
        ans = min(ans, D[1][i][j] + D[2][i][j] + D[3][i][j] - 2);
      }
    }
  }

  if(ans > N*M) cout << -1 << endl;
  else cout << ans << endl;
}
