#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int N, M;
char C[100003][12];
pair<int, int> nex[100003][12];
bool loop[100003][12];
bool vis[100003][12];
vector<pair<int, int> > ord, new_ord;  // reverse topological order
int BLOCK_SIZE;

inline bool outside(int i, int j) {
  return (i < 0 || i >= N || j < 0 || j >= M);
}

void dfs(int i, int j) {
  if(vis[i][j]) return;
  if(outside(i, j)) return;

  vis[i][j] = true;

  if(C[i][j] == '>') dfs(i, j + 1);
  else if(C[i][j] == '<') dfs(i, j - 1);
  else if(C[i][j] == '^') dfs(i - 1, j);

  ord.push_back({i, j});
}

void selective_dfs(int i, int j, int block) {
  if(outside(i, j)) return;
  if(i/BLOCK_SIZE != block) return;
  if(vis[i][j]) return;

  vis[i][j] = true;

  if(C[i][j] == '>') selective_dfs(i, j + 1, block);
  else if(C[i][j] == '<') selective_dfs(i, j - 1, block);
  else if(C[i][j] == '^') selective_dfs(i - 1, j, block);

  new_ord.push_back({i, j});
}

int main() {
  int Q; scanf("%d %d %d", &N, &M, &Q);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      scanf(" %c", &C[i][j]);
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(vis[i][j]) continue;
      dfs(i, j);
    }
  }

  BLOCK_SIZE = int(sqrt(N));

  for(auto it: ord) {
    int i = it.first, j = it.second;
    int n_i = i, n_j = j;

    if(C[i][j] == '>') n_j++;
    else if(C[i][j] == '<') n_j--;
    else if(C[i][j] == '^') n_i--;

    if(outside(n_i, n_j)) {
      nex[i][j] = {n_i, n_j};
    }
    else {
      if(n_i/BLOCK_SIZE != i/BLOCK_SIZE) {
        nex[i][j] = {n_i, n_j};
      }
      else {
        if(loop[n_i][n_j]) loop[i][j] = true;
        else {
          if((C[i][j] == '>' && C[n_i][n_j] == '<') || (C[i][j] == '<' && C[n_i][n_j] == '>')) loop[i][j] = true;
        }
        nex[i][j] = nex[n_i][n_j];
      }
    }
  }

  while(Q--) {
    char type; scanf(" %c", &type);

    if(type == 'A') {
      int x, y; scanf(" %d %d", &x, &y); x--; y--;
      bool looped = false;
      while(!outside(x, y)) {
        if(loop[x][y]) {
          looped = true;
          break;
        }
        int n_x = nex[x][y].first, n_y = nex[x][y].second;
        x = n_x;
        y = n_y;
      }
      if(looped) {
        printf("-1 -1\n");
      }
      else {
        printf("%d %d\n", x + 1, y + 1);
      }
    }
    else {
      int x, y; char c; scanf(" %d %d %c", &x, &y, &c); x--; y--;

      C[x][y] = c;
      int block_id = x/BLOCK_SIZE;
      for(int i = block_id * BLOCK_SIZE; i < (block_id + 1) * BLOCK_SIZE && i < N; i++) {
        for(int j = 0; j < M; j++) {
          vis[i][j] = false;
          loop[i][j] = false;
        }
      }
      new_ord.clear();
      for(int i = block_id * BLOCK_SIZE; i < (block_id + 1) * BLOCK_SIZE && i < N; i++) {
        for(int j = 0; j < M; j++) {
          if(!vis[i][j]) selective_dfs(i, j, block_id);
        }
      }

      for(auto it: new_ord) {
        int i = it.first, j = it.second;

        int n_i = i, n_j = j;
        if(C[i][j] == '>') n_j++;
        else if(C[i][j] == '<') n_j--;
        else if(C[i][j] == '^') n_i--;

        if(outside(n_i, n_j)) {
          nex[i][j] = {n_i, n_j};
        }
        else {
          if(n_i/BLOCK_SIZE != i/BLOCK_SIZE) {
            nex[i][j] = {n_i, n_j};
          }
          else {
            if(loop[n_i][n_j]) loop[i][j] = true;
            else {
              if((C[i][j] == '>' && C[n_i][n_j] == '<') || (C[i][j] == '<' && C[n_i][n_j] == '>')) loop[i][j] = true;
            }

            nex[i][j] = nex[n_i][n_j];
          }
        }
      }
    }
  }
}
