#include <iostream>
#include <algorithm>

using namespace std;

int N, M, x, y;
char A[1000][1000];
int black[1000], white[1000];
int dp[1000][1000][2];

// i = Position, j = num continuous, k = color (0 = black, 1 = white)
int solve(int i, int j, int k) {
  if(i == M) {
    if(j == 0 || (j >= x && j <= y)) return 0;
    else return 10000000;
  }
  if(dp[i][j][k] != -1) return dp[i][j][k];

  int ans = 10000000;
  if(k == 0) {
    if((j + 1) < y) ans = min(ans, N - black[i] + solve(i + 1, j + 1, 0));
    if((j + 1) >= x) ans = min(ans, N - black[i] + solve(i + 1, 0, 1));
  }
  else {
    if((j + 1) < y) ans = min(ans, N - white[i] + solve(i + 1, j + 1, 1));
    if((j + 1) >= x) ans = min(ans, N - white[i] + solve(i + 1, 0, 0));
  }

  return dp[i][j][k] = ans;
}

int main() {
  cin >> N >> M >> x >> y;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> A[i][j];

      if(A[i][j] == '#') black[j]++;
      else white[j]++;
    }
  }

  for(int i = 0; i < 1000; i++) {
    for(int j = 0; j < 1000; j++) {
      dp[i][j][0] = dp[i][j][1] = -1;
    }
  }

  int ans = min(solve(0, 0, 0), solve(0, 0, 1));
  if(ans == 10000000) ans = 0;

  cout << ans << endl;
}
