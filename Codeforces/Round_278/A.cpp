#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  int H_Y, A_Y, D_Y; cin >> H_Y >> A_Y >> D_Y;
  int H_M, A_M, D_M; cin >> H_M >> A_M >> D_M;

  int h, a, d; cin >> h >> a >> d;

  int ans = INT_MAX/2;
  for(int i = 0; i <= 3000; i++) {  // hp
    for(int j = 0; j <= 200; j++) { // attack
      for(int k = 0; k <= 200; k++) {  // defense
        int d_Y = max(0, A_M - (D_Y + k));
        int d_M = max(0, (A_Y + j) - D_M);

        if(d_M == 0) continue;

        int t_Y = d_Y == 0 ? INT_MAX/2 : ((H_Y + i) + d_Y - 1)/d_Y;
        int t_M = (H_M + (d_M - 1))/d_M;

        if(t_Y > t_M) {
          int curr = i * h + j * a + k * d;
          if(curr < ans) {
            ans = curr;
          }
        }
      }
    }
  }

  cout << ans << endl;
}
