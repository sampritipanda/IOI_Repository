#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;

  while(T--) {
    long long x, m; cin >> x >> m;

    if(m == 0LL) cout << "BOB" << endl;
    else if(x == 0LL && m == 1LL) cout << "BOB" << endl;
    else if(x == 2LL) {
      if((m + 1LL) % 4LL == 0LL) cout << "BOB" << endl;
      else cout << "ALICE" << endl;
    }
    else if(x % 4LL == 2LL || x % 4LL == 3LL) {
      cout << "ALICE" << endl;
    }
    else {
      if(m % 4LL == 0LL) cout << "BOB" << endl;
      else cout << "ALICE" << endl;
    }
  }
}

