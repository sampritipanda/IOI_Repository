#include <iostream>
#include <algorithm>

using namespace std;

int A[100001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M, Q; cin >> N >> M >> Q;

  while(M--) {
    int u, v; cin >> u >> v;
    if(u > v) swap(u, v);
    v--;
    for(int i = u; i <= v; i++) A[i]++;
  }

  while(Q--) {
    int t, u, v; cin >> t >> u >> v;
    if(u > v) swap(u, v);
    v--;

    if(t == 0) {
      for(int i = u; i <= v; i++) A[i]++;
    }
    else if(t == 1) {
      for(int i = u; i <= v; i++) A[i]--;
    }
    else {
      int ans = 0;
      for(int i = u; i <= v; i++) {
        if(A[i] == 0) ans++;
      }
      cout << ans << endl;
    }
  }
}
