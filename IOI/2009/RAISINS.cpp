#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int A[51][51];
int P[51][51];
int dp[51][51][51][51];

int solve(int x1, int y1, int x2, int y2) {
  if(x1 == x2 && y1 == y2) return 0;
  if(dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];

  int curr = P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
  int ans = INT_MAX;

  for(int i = x1; i < x2; i++) {
    ans = min(ans, curr + solve(x1, y1, i, y2) + solve(i + 1, y1, x2, y2));
  }
  for(int j = y1; j < y2; j++) {
    ans = min(ans, curr + solve(x1, y1, x2, j) + solve(x1, j + 1, x2, y2));
  }

  return dp[x1][y1][x2][y2] = ans;
}

int main() {
  int N, M; scanf("%d %d", &N, &M);

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      scanf("%d", &A[i][j]);
      P[i][j] = A[i][j] + P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
    }
  }

  memset(dp, -1, sizeof dp);

  printf("%d\n", solve(1, 1, N, M));
}
