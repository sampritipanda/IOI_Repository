#include <iostream>
#include <algorithm>

using namespace std;

double dp[1001][1001];
bool pos[1001][1001];

int main() {
  for(int i = 0; i <= 1000; i++) {
    for(int j = 0; j <= 1000; j++) {
      pos[i][j] = false;
      dp[i][j] = 0;
    }
  }

  int N, M; cin >> N >> M;
  int K; cin >> K;

  while(K--) {
    int x, y; cin >> x >> y;
    pos[x][y] = true;
  }

  double a = 100.0, b = 100.0 * sqrt(2.0);

  dp[0][0] = 0;
  for(int i = 1; i <= N; i++) {
    dp[i][0] = dp[i - 1][0] + a;
  }
  for(int j = 1; j <= M; j++) {
    dp[0][j] = dp[0][j - 1] + a;
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      dp[i][j] = a + min(dp[i - 1][j], dp[i][j - 1]);
      if(pos[i][j]) dp[i][j] = min(dp[i][j], b + dp[i - 1][j - 1]);
    }
  }

  cout << round(dp[N][M]) << endl;

  return 0;
}
