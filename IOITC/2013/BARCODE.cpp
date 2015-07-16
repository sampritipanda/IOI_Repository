// Bar Code

#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int N, M, X, Y;
bool black[1010][1010];
int column_sum[2][1010]; // [0][i] = white, [1][i] = black
int prefix_sum[2][1010];
int memo[1010][2];

int calc_sum(int i, int j, int color){
  if(i == 0) return prefix_sum[color][j];
  else return prefix_sum[color][j] - prefix_sum[color][i - 1];
}

// 0 = white, 1 = black
int solve(int i, int color){
  if(i == M) return 0;
  if(memo[i][color] != -1) return memo[i][color];

  int ans = 2000000;
  int op_color = (color == 1 ? 0 : 1);
  for(int j = i + X - 1; j <= min(i + Y - 1, M - 1); j++){
    ans = min(ans, calc_sum(i, j, op_color) + solve(j + 1, op_color));
  }
  memo[i][color] = ans;
  return ans;
}

int main() {
  memset(black, false, sizeof black);
  memset(column_sum, 0, sizeof column_sum);
  memset(prefix_sum, 0, sizeof prefix_sum);
  memset(memo, -1, sizeof memo);

  cin >> N >> M >> X >> Y;

  for(int i = 0; i < N; i++){
    string s; cin >> s;
    for(int j = 0; j < M; j++){
      black[i][j] = (s[j] == '#');
    }
  }

  for(int j = 0; j < M; j++){
    for(int i = 0; i < N; i++){
      column_sum[black[i][j] ? 1 : 0][j]++;
    }
  }

  prefix_sum[0][0] = column_sum[0][0]; prefix_sum[1][0] = column_sum[1][0];
  for(int j = 1; j < M; j++){
    prefix_sum[0][j] = column_sum[0][j] + prefix_sum[0][j - 1];
    prefix_sum[1][j] = column_sum[1][j] + prefix_sum[1][j - 1];
  }

  int ans = min(solve(0, 0), solve(0, 1));
  if(ans >= 2000000) ans = 0;
  cout << ans << endl;
}
