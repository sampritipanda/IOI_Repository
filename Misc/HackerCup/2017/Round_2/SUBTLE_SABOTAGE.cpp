// Subtle Sabotage

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    int N, M, K; cin >> N >> M >> K;
    int ans = INT_MAX;

    if (1 + K + 1 + K + 1 <= N) ans = min(ans, (M + K - 1)/K - 1 + 1);
    if (1 + K + 1 + K + 1 <= M) ans = min(ans, (N + K - 1)/K - 1 + 1);
    if (4 * K + 1 <= N) ans = min(ans, 5);
    if (4 * K + 1 <= M) ans = min(ans, 5);

    if (ans == INT_MAX) ans = -1;

    cout << "Case #" << t << ": " << ans << endl;
  }
}
