// Save Spaceman Spiff

#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
vector<vector<int> > B;
bool grid[2501][2501], dp[2501][2501];

int check(int x, int y, int t) {
  if(x - 1 + y - 1 == t) grid[x][y] = false;
}

int main() {
  cin >> N >> M >> K;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      grid[i][j] = true;
    }
  }

  for(int i = 0; i < K; i++) {
    int x, y, t, f; cin >> x >> y >> t >> f;
    B.push_back({x, y, t, f});
  }

  for(int k = 0; k < K; k++) {
    int x = B[k][0], y = B[k][1], T = B[k][2], f = B[k][3];

    for(int t = T; t <= N + M; t += f) {
      int t2 = t, i = x, j = y;
      while(i >= 1) {
        check(i, j, t2);
        t2++; i--;
      }

      t2 = t, i = x, j = y;
      while(i <= N) {
        check(i, j, t2);
        t2++; i++;
      }

      t2 = t, i = x, j = y;
      while(j >= 1) {
        check(i, j, t2);
        t2++; j--;
      }

      t2 = t, i = x, j = y;
      while(j <= M) {
        check(i, j, t2);
        t2++; j++;
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(i == 1 && j == 1) dp[i][j] = grid[i][j];
      else {
        if(grid[i][j] == false) dp[i][j] = false;
        else {
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }
      }
    }
  }

  if(dp[N][M]) {
    cout << "YES" << endl;
    cout << N - 1 + M - 1 << endl;
  }
  else cout << "NO" << endl;
}
