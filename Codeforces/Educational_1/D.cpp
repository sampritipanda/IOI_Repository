#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

bool grid[1001][1001], visited[1001][1001];
int component[1001][1001];
map<int, int> ans;
int id = 0;
int N, M;

void dfs(int i, int j) {
  if(i < 1 || i > N || j < 1 || j > M) return;
  if(grid[i][j]) {
    ans[id]++;
    return;
  }

  if(visited[i][j]) return;

  visited[i][j] = true;
  component[i][j] = id;

  dfs(i + 1, j);
  dfs(i - 1, j);
  dfs(i, j + 1);
  dfs(i, j - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  memset(grid, false, sizeof grid);
  memset(visited, false, sizeof visited);

  int K; cin >> N >> M >> K;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      char c; cin >> c;
      if(c == '*') grid[i][j] = true;
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(grid[i][j] || visited[i][j]) continue;

      id++;
      ans[id] = 0;
      dfs(i, j);
    }
  }

  while(K--) {
    int x, y; cin >> x >> y;
    cout << ans[component[x][y]] << endl;
  }
}
