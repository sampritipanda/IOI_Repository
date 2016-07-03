#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    long long N, M; cin >> N >> M;

    cout << (2 * N - 1) * (M - 1) + N - 1 << endl;
  }
}
