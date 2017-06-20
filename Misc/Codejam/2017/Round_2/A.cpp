#include <iostream>
#include <algorithm>

using namespace std;

int G[101];

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    int N, P; cin >> N >> P;
    int F[4] = {0, 0, 0, 0};
    for(int i = 1; i <= N; i++) {
      cin >> G[i];
      F[G[i] % P]++;
    }

    int ans = 0;

    if(P == 2) {
      ans += F[0];
      ans += (F[1] + 1)/2;
    }
    else if(P == 3) {
      ans += F[0];
      int v = min(F[1], F[2]);
      ans += v;
      F[1] -= v;
      F[2] -= v;
      ans += (F[1] + 2)/3;
      ans += (F[2] + 2)/3;
    }
    else {
      ans += F[0];
      int v = min(F[1], F[3]);
      ans += v;
      F[1] -= v;
      F[3] -= v;

      if(F[1] > 0) {
        v = min(F[1]/2, F[2]);
        ans += v;
        F[1] -= 2 * v;
        F[2] -= v;
      }
      else if(F[3] > 0) {
        v = min(F[3]/2, F[2]);
        ans += v;
        F[3] -= 2 * v;
        F[2] -= v;
      }

      ans += (F[2] + 1)/2;
      if(F[2] % 2 == 0) {
        ans += (F[1] + 3)/4;
        ans += (F[3] + 3)/4;
      }
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
}
