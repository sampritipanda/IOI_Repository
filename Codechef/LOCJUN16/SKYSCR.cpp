#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    long long N, M; cin >> N >> M;

    cout << abs(N - M) << endl;
  }
}
