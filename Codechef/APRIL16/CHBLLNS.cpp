#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int R, G, B; cin >> R >> G >> B;
    int K; cin >> K;

    long long ans = 0;
    ans += min(K - 1, R);
    ans += min(K - 1, G);
    ans += min(K - 1, B);
    ans++;

    cout << ans << endl;
  }
}
