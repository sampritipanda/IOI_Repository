#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    int ans = 0;
    for(int i = 0; i < N; i++) {
      int a; cin >> a;
      ans = __gcd(ans, a);
    }
    cout << ans << endl;
  }
}
