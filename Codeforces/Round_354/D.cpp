#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

char A[1001][1001];
int D[1001][1001][4];

char rotate(char c, int r) {
  if(r == 0) return c;

  if(c == '-') c = '|';
  else if(c == '|') c = '-';
  else if(c == '^') c = '>';
  else if(c == '>') c = 'v';
  else if(c == 'v') c = '<';
  else if(c == '<') c = '^';
  else if(c == 'L') c = 'U';
  else if(c == 'U') c = 'R';
  else if(c == 'R') c = 'D';
  else if(c == 'D') c = 'L';

  return rotate(c, r - 1);
}

bool check_left(char S) {
  return (S == '+' || S == '-' || S == '<' || S == 'R' || S == 'U' || S == 'D');
}

bool check_right(char S) {
  return (S == '+' || S == '-' || S == '>' || S == 'L' || S == 'U' || S == 'D');
}

bool check_top(char S) {
  return (S == '+' || S == '|' || S == '^' || S == 'L' || S == 'R' || S == 'D');
}

bool check_bottom(char S) {
  return (S == '+' || S == '|' || S == 'v' || S == 'L' || S == 'R' || S == 'U');
}

char temp_S[1005];

int main() {
  int N, M; scanf("%d %d", &N, &M);

  for(int i = 1; i <= N; i++) {
    scanf(" %s", temp_S);
    for(int j = 1; j <= M; j++) {
      A[i][j] = temp_S[j - 1];
    }
  }

  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= M; j++) {
      for(int k = 0; k < 4; k++) {
        D[i][j][k] = -1;
      }
    }
  }

  int x_s, y_s; scanf("%d %d", &x_s, &y_s);
  int x_t, y_t; scanf("%d %d", &x_t, &y_t);

  // {x, y, r, d}
  queue<vector<int> > Q;
  Q.push({x_s, y_s, 0, 0});
  int ans = -1;

  while(!Q.empty()) {
    auto it = Q.front(); Q.pop();
    int x = it[0], y = it[1], r = it[2], d = it[3];

    if(D[x][y][r] != -1) continue;
    D[x][y][r] = d;

    if(x == x_t && y == y_t) {
      ans = d;
      break;
    }

    if(D[x][y][(r + 1) % 4] == -1){
      Q.push({x, y, (r + 1) % 4, d + 1});
    }
    if(y < M && check_right(rotate(A[x][y], r)) && check_left(rotate(A[x][y + 1], r))) {
      if(D[x][y + 1][r] == -1)
        Q.push({x, y + 1, r, d + 1});
    }
    if(y > 1 && check_left(rotate(A[x][y], r)) && check_right(rotate(A[x][y - 1], r))) {
      if(D[x][y - 1][r] == -1)
        Q.push({x, y - 1, r, d + 1});
    }
    if(x < N && check_bottom(rotate(A[x][y], r)) && check_top(rotate(A[x + 1][y], r))) {
      if(D[x + 1][y][r] == -1)
        Q.push({x + 1, y, r, d + 1});
    }
    if(x > 1 && check_top(rotate(A[x][y], r)) && check_bottom(rotate(A[x - 1][y], r))) {
      if(D[x - 1][y][r] == -1)
        Q.push({x - 1, y, r, d + 1});
    }
  }

  printf("%d\n", ans);
}
