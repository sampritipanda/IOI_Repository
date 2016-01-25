#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

char grid[1000][1000];
int visited[1000][1000];
int sizes[1000001];
int N, M;
int curr_size = 0, curr_color = 0;

void dfs(int i, int j) {
  if(i < 0 || i >= N || j < 0 || j >= M) return;
  if(grid[i][j] == '*') return;
  if(visited[i][j]) return;

  visited[i][j] = curr_color;
  curr_size++;

  dfs(i + 1, j);
  dfs(i - 1, j);
  dfs(i, j + 1);
  dfs(i, j - 1);
}

int main() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> grid[i][j];
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(visited[i][j] || grid[i][j] == '*') continue;
      ++curr_color;
      curr_size = 0;
      dfs(i, j);
      sizes[curr_color] = curr_size;
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(grid[i][j] == '.') cout << ".";
      else {
        set<int> C;
        if(i + 1 < N) C.insert(visited[i + 1][j]);
        if(i - 1 >= 0) C.insert(visited[i - 1][j]);
        if(j + 1 < M) C.insert(visited[i][j + 1]);
        if(j - 1 >= 0) C.insert(visited[i][j - 1]);

        int ans = 1;
        for(auto c: C) ans += sizes[c];
        cout << ans % 10;
      }
    }
    cout << endl;
  }
}
