#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int A[11][11];
int dp[11][11][1 << 11][2];
int N, M;

int solve(int i, int j, int col_mask, int prev_row) {
  if(i == N + 1) return 0;
  if(dp[i][j][col_mask][prev_row] != -1) return dp[i][j][col_mask][prev_row];

  int ans = INT_MAX/2;
  int nxt_i = (j == M ? i + 1 : i), nxt_j = (j == M ? 1 : j + 1);
  if(A[i][j]) {
    // vertical
    ans = min(ans, ((col_mask & (1 << j)) ? 0 : 1) + solve(nxt_i, nxt_j, col_mask | (1 << j), 0));
    // horizontal
    ans = min(ans, !prev_row + solve(nxt_i, nxt_j, col_mask & ~(1 << j), (j == M ? 0 : 1)));
  }
  else {
    ans = min(ans, solve(nxt_i, nxt_j, col_mask & ~(1 << j), 0));
  }
  return dp[i][j][col_mask][prev_row] = ans;
}

class FloorBoards {
  public:
  int layout(vector <string> room) {
    N = room.size();
    M = room[0].size();
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        A[i + 1][j + 1] = (room[i][j] == '.' ? 1 : 0);
      }
    }

    memset(dp, -1, sizeof dp);
    return solve(1, 1, 0, 0);
  }
};

int main() {
  FloorBoards test;
  cout << test.layout({"..", ".."}) << endl;
}
