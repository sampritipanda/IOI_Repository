// Stockholm Encryption

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int T; cin >> T;

  while(T--) {
    long long N; cin >> N;

    double required = ceil(N/26.0);
    cout << (long long)(required) << endl;
  }
}
