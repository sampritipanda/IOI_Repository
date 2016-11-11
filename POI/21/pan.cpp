// Solar Panels

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int A_L, A_R, B_L, B_R; cin >> A_L >> A_R >> B_L >> B_R;

    if(A_L > B_L) {
      swap(A_L, B_L);
      swap(A_R, B_R);
    }

    int ans = 0;
    for(int i = 1; i*i <= B_R; i++) {
      int j = A_R/i, k = B_R/i;
      if(i * (A_R/i) >= A_L && i * (B_R/i) >= B_L) ans = max(ans, i);
      if(j * (A_R/j) >= A_L && j * (B_R/j) >= B_L) ans = max(ans, j);
      if(k * (A_R/k) >= A_L && k * (B_R/k) >= B_L) ans = max(ans, k);
    }
    cout << ans << endl;
  }
}
