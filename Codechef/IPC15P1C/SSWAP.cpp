#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;

  while(T--) {
    string S; cin >> S;
    int N = S.length();
    int D; cin >> D;

    string T = "";
    if(D > 1) T += S.substr(0, D - 1);
    if(N % 2 == 0) {
      if(D % 2 == 0) reverse(T.begin(), T.end());
    }
    else {
      if(D % 2 == 1) reverse(T.begin(), T.end());
    }

    cout << S.substr(D - 1);
    cout << T << endl;
  }
}
