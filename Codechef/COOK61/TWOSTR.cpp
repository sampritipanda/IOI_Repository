// Chef and the Wildcard Matching

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    string X, Y; cin >> X >> Y;
    int N = X.length();

    bool possible = true;
    for(int i = 0; i < N; i++) {
      if(X[i] != Y[i] && X[i] != '?' && Y[i] != '?') {
        possible = false;
        break;
      }
    }

    if(possible) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
