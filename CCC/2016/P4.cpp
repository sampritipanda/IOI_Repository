#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char grid[10000][10][10];

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
    for(int j = i + 1; j < G; j++) {
      bool valid = true;
      for(int k = 0; k < N; k++) {
        int cnt = 0;
        for(int l = 0; l < N; l++) {
          if(grid[i][k][l] != grid[j][k][l]) cnt++;
        }
        if((N % 2 == 0 && cnt % 2 != 0) || (N % 2 == 1 && cnt % 4 != 0)) {
          valid = false;
          break;
        }
      }
      if(valid) ans++;
    }
  }

  cout << ans << endl;
}
