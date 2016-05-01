#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    int ans = 1;
    while(N - ans >= 0) {
      N -= ans;
      ans++;
    }
    cout << ans - 1 << endl;
  }
}
