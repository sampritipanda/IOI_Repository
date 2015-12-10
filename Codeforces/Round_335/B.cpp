#include <iostream>
#include <algorithm>

using namespace std;

bool visited[501][501];
int ans[100002];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M, x, y; cin >> N >> M >> x >> y;

  for(int i = 0; i <= N; i++) {
    ans[i] = 0;
    for(int j = 0; j <= M; j++) {
      visited[i][j] = false;
    }
  }

  int steps = 0;
  ans[steps] += 1;
  visited[x][y] = true;

  string S; cin >> S;
  for(auto c: S) {
    steps++;

    int a = x, b = y;;
    if(c == 'U') {
      a--;
    }
    else if(c == 'D') {
      a++;
    }
    else if(c == 'L') {
      b--;
    }
    else {
      b++;
    }

    if(a >= 1 && a <= N && b >= 1 && b <= M) {
      if(!visited[a][b]) ans[steps] += 1;
      visited[a][b] = true;
      x = a, y = b;
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(!visited[i][j]) ans[steps]++;
    }
  }

  for(int i = 0; i <= steps; i++) cout << ans[i] << " ";
  cout << endl;
}
