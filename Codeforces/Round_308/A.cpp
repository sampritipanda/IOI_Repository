// Vanya and Table

#include <iostream>

using namespace std;

int main() {
  int N; cin >> N;
  int grid[101][101];
  for(int i = 1; i <= 100; i++) {
    for(int j = 1; j <= 100; j++) {
      grid[i][j] = 0;
    }
  }

  while(N--) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    for(int i = y1; i <= y2; i++) {
      for(int j = x1; j <= x2; j++) {
        grid[i][j]++;
      }
    }
  }

  int ans = 0;
  for(int i = 1; i <= 100; i++) {
    for(int j = 1; j <= 100; j++) {
      ans += grid[i][j];
    }
  }

  cout << ans << endl;
}
