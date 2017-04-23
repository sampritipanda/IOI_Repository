#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string A[1000];
bool vis[1000][1000][4][4];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int N, M; cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> A[i];

  int start_i, start_j, end_i, end_j;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(A[i][j] == 'S') {
        start_i = i;
        start_j = j;
      }
      else if(A[i][j] == 'T') {
        end_i = i;
        end_j = j;
      }
    }
  }

  queue<vector<int> > Q; // {i, j, direction, turns}
  Q.push({start_i, start_j, 0, 0});
  Q.push({start_i, start_j, 1, 0});
  Q.push({start_i, start_j, 2, 0});
  Q.push({start_i, start_j, 3, 0});

  bool pos = false;
  while(!Q.empty()) {
    auto it = Q.front(); Q.pop();
    int i = it[0], j = it[1], direction = it[2], turns = it[3];

    if(vis[i][j][direction][turns]) continue;
    vis[i][j][direction][turns] = 1;
    if(turns > 2) continue;
    if(i == end_i && j == end_j) {
      pos = true;
      break;
    }
    if(A[i][j] == '*') continue;

    if(i < N - 1 && ((direction == 0 && turns <= 2) || turns <= 1)) Q.push({i + 1, j, 0, turns + (direction == 0 ? 0 : 1)});
    if(i > 0 && ((direction == 1 && turns <= 2) || turns <= 1)) Q.push({i - 1, j, 1, turns + (direction == 1 ? 0 : 1)});
    if(j < M - 1 && ((direction == 2 && turns <= 2) || turns <= 1))  Q.push({i, j + 1, 2, turns + (direction == 2 ? 0 : 1)});
    if(j > 0 && ((direction == 3 && turns <= 2) || turns <= 1)) Q.push({i, j - 1, 3, turns + (direction == 3 ? 0 : 1)});
  }

  if(pos) cout << "YES" << endl;
  else cout << "NO" << endl;
}
