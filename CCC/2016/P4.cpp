#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int grid[10000][10];
int grid2[10000][10];
bool pos[1 << 10][1 << 10];
int vis[10000];

int main() {
  for(int i = 0; i < (1 << 10); i++) {
    for(int j = 0; j < (1 << 10); j++) {
      if(__builtin_popcount(i ^ j) % 2 == 0) pos[i][j] = true;
    }
  }
  int N; cin >> N;
  int G; cin >> G;

  for(int i = 0; i < G; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
        char c; cin >> c;
        if(c == 'R') {
          grid[i][j] |= (1 << k);
          grid2[i][k] |= (1 << j);
        }
      }
    }
  }

  int ans = 0;

  for(int i = 0; i < G; i++) {
    if(vis[i]) continue;
    vis[i] = true;
    int size = 1;
    for(int j = i + 1; j < G; j++) {
      if(vis[j]) continue;
      bool valid = true;
      for(int k = 0; k < N; k++) {
        if(!pos[grid[i][k]][grid[j][k]]) {
          valid = false;
          break;
        }
      }
      if(valid) {
        for(int l = 0; l < N; l++) {
          if(!pos[grid2[i][l]][grid2[j][l]]) {
            valid = false;
            break;
          }
        }
      }

      if(valid) {
        size++;
        vis[j] = true;
      }
    }
    ans += (size * (size - 1))/2;
  }

  cout << ans << endl;
}
