#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char grid[10000][10][10];
int vis[10000];

int main() {
  int N; cin >> N;
  int G; cin >> G;

  for(int i = 0; i < G; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
        cin >> grid[i][j][k];
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
        int cnt = 0;
        for(int l = 0; l < N; l++) {
          if(grid[i][k][l] != grid[j][k][l]) cnt++;
        }
        if(cnt % 2 != 0) {
          valid = false;
          break;
        }
      }
      if(valid) {
        for(int l = 0; l < N; l++) {
          int cnt = 0;
          for(int k = 0; k < N; k++) {
            if(grid[i][k][l] != grid[j][k][l]) cnt++;
          }
          if(cnt % 2 != 0) {
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
