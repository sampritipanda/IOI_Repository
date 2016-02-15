#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;

  while(T--) {
    long long N; cin >> N;
    cout << 2 * N - 1 << endl;
  }
}
