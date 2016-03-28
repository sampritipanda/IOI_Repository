#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int ans[101][101];
bool vis[101][101];
queue<vector<int> > Q;

int main() {
  int N, A, B; cin >> N >> A >> B;

  if(N > A * B) cout << -1 << endl;
  else {
    Q.push({1, 1, 1}); // {x, y, odd/even}
    int odd = 1, even = 2;

    while(!Q.empty()) {
      auto it = Q.front(); Q.pop();

      int x = it[0], y = it[1], parity = it[2];
      if(x > A || y > B) continue;
      if(vis[x][y]) continue;
      vis[x][y] = true;

      if(parity == 0) {
        ans[x][y] = even;
        even += 2;
      }
      else {
        ans[x][y] = odd;
        odd += 2;
      }
      if(ans[x][y] > N) ans[x][y] = 0;

      Q.push({x + 1, y, 1 - parity});
      Q.push({x, y + 1, 1 - parity});
    }

    for(int i = 1; i <= A; i++) {
      for(int j = 1; j <= B; j++) cout << ans[i][j] << " ";
      cout << endl;
    }
  }
}
