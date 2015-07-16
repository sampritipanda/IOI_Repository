// Counter Culture

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

bool grid[100][100];

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++){
    int R, C, N; cin >> R >> C >> N;
    int total_cells = R*C;

    int ans = INT_MAX;
    for(int mask = 0; mask < (1 << total_cells); mask++){
      if(__builtin_popcount(mask) != N) continue;

      if(mask == 30557) {
        int sdjkg = 54;
      }

      for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
          grid[R - i - 1][C - j - 1] = (mask & (1 << (i * R + j))) > 0;
        }
      }

      int unhappiness = 0;
      for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
          if(!grid[i][j]) continue;

          if(i < (R - 1) && grid[i + 1][j]) unhappiness++;
          if(j < (C - 1) && grid[i][j + 1]) unhappiness++;
        }
      }
      ans = min(ans, unhappiness);
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
}
