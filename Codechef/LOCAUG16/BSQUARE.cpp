#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  int T; cin >> T;

  while(T--) {
    long long N; cin >> N;

    cout << (4 * N)/gcd(4 * N, N + 1) << endl;
  }
}
