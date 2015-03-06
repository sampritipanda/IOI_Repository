// Fox And Two Dots

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool visited[60][60];
int N, M;

bool dfs(int i, int j, int k, int parent_i, int parent_j, char color, vector<string>& graph) {
  visited[i][j] = true;

  if(i - 1 >= 0  && graph[i - 1][j] == color){
    if(!visited[i - 1][j]){
      if(dfs(i - 1, j, k + 1, i, j, color, graph)) {
        return true;
      }
    }
    else if(((i - 1) != parent_i || j != parent_j) && k >= 4){
      return true;
    }
  }
  if(i + 1 < N  && graph[i + 1][j] == color){
    if(!visited[i + 1][j]){
      if(dfs(i + 1, j, k + 1, i, j, color, graph)) {
        return true;
      }
    }
    else if(((i + 1) != parent_i || j != parent_j) && k >= 4){
      return true;
    }
  }
  if(j - 1 >= 0  && graph[i][j - 1] == color){
    if(!visited[i][j - 1]){
      if(dfs(i, j - 1, k + 1, i, j, color, graph)) {
        return true;
      }
    }
    else if((i != parent_i || (j - 1) != parent_j) && k >= 4){
      return true;
    }
  }
  if(j + 1 < M  && graph[i][j + 1] == color){
    if(!visited[i][j + 1]){
      if(dfs(i, j + 1, k + 1, i, j, color, graph)) {
        return true;
      }
    }
    else if((i != parent_i || (j + 1) != parent_j) && k >= 4){
      return true;
    }
  }

  return false;
}

int main() {
  cin >> N >> M;
  vector<string> grid(N);
  for(int i = 0; i < N; i++){
    cin >> grid[i];
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      visited[i][j] = false;
    }
  }

  bool flag = false;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(!visited[i][j]){
        if(dfs(i, j, 1, -1, -1, grid[i][j], grid)) {
          flag = true;
          break;
        }
      }
    }
    if(flag) break;
  }

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
