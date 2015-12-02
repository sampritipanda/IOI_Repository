#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

#define INF 1000000007

int N;
int A[501][501];
bool safe[501][501];
bool dp_safe[501][501];
int dp[501][501];

void mark(int x, int y) {
  if(x >= 1 && x <= N && y >= 1 && y <= N) safe[x][y] = true;
}

int main() {
  int M; cin >> N >> M;

  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= N; j++) {
      safe[i][j] = false;
      dp_safe[i][j] = false;
      dp[i][j] = -INF;
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> A[i][j];
    }
  }

  while(M--) {
    int x, y, k; cin >> x >> y >> k;

    for(int i = 0; i <= k; i++) {
      for(int j = 0; i + j <= k; j++) {
        mark(x + i, y + j);
        mark(x + i, y - j);
        mark(x - i, y + j);
        mark(x - i, y - j);
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      if(i == 1 && j == 1) dp_safe[i][j] = safe[i][j];
      else {
        dp_safe[i][j] = safe[i][j] && (dp_safe[i - 1][j] || dp_safe[i][j - 1]);
      }
    }
  }

  if(dp_safe[N][N]) {
    cout << "YES" << endl;
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        if(i == 1 && j == 1) dp[i][j] = A[i][j];
        else {
          if(!safe[i][j]) dp[i][j] = -INF;
          else if(!safe[i - 1][j] && !safe[i][j - 1]) dp[i][j] = -INF;
          else {
            dp[i][j] = A[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
          }
        }
      }
    }
    cout << dp[N][N] << endl;
  }
  else cout << "NO" << endl;
}
