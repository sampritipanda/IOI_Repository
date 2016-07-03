#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N, M; cin >> N >> M;

    vector<int> msk(N, 0);

    for(int i = 0; i < N; i++) msk[i] |= (1 << i);

    while(M--) {
      int u, v; cin >> u >> v; u--; v--;
      msk[u] |= (1 << v);
      msk[v] |= (1 << u);
    }

    int ans = INT_MAX/2;

    for(int mask = 0; mask < (1 << N); mask++) {
      int vis = 0;
      int cnt = 0;
      for(int i = 0; i < N; i++) {
        if(mask & (1 << i)) {
          cnt++;
          vis |= msk[i];
        }
      }
      bool pos = true;
      for(int i = 0; i < N; i++) {
        if(!(vis & (1 << i))) {
          pos = false;
          break;
        }
      }
      if(pos) {
        ans = min(ans, cnt);
      }
    }

    cout << ans << endl;
  }
}
