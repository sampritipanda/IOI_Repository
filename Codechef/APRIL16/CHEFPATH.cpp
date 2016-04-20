#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    long long N, M; cin >> N >> M;

    if(N > M) swap(N, M);

    if(N == 1) {
      if(M == 2) cout << "Yes";
      else cout << "No";
    }
    else if(N % 2 == 0 || M % 2 == 0) cout << "Yes";
    else cout << "No";

    cout << endl;
  }
}
