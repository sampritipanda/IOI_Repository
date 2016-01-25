#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int N, M, K; cin >> N >> M >> K;
    cout << max(abs(N - M) - K, 0) << endl;
  }
}
