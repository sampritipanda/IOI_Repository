#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;

  while(T--) {
    long long N; cin >> N;
    for(int i = 0; i < N; i++) {
      int x; cin >> x;
    }

    if(N == 1) cout << 1 << endl;
    else if(N == 2) cout << 2 << endl;
    else {
      long long ans = (N - 2) * 2;
      ans += (N - 2) * (N - 1);
      ans %= 100000;

      cout << ans << endl;
    }
  }
}
