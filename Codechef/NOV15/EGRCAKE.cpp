#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
  if(b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
  int T; cin >> T;

  while(T--) {
    int N, M; cin >> N >> M;

    if(N == 1) cout << "Yes" << endl;
    else if(M == 0) cout << "No 1" << endl;
    else if(gcd(N, M) == 1) cout << "Yes" << endl;
    else cout << "No " << N/gcd(N, M) << endl;
  }
}
