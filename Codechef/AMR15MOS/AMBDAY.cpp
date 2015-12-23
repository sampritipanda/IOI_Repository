#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int F; long long H, W; cin >> F >> H >> W;
    int P[502];
    P[0] = 0;
    long long ans = LLONG_MAX;
    for(int i = 1; i <= F; i++) {
      cin >> P[i];
    }
    P[F + 1] = W;
    sort(P, P + F + 2);

    for(int i = 1; i <= F + 1; i++) {
      ans = min(ans, (P[i] - P[i - 1]) * H);
    }

    cout << ans << endl;
  }
}
