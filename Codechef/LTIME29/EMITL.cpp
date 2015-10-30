// emitL

#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    string S; cin >> S;
    int N = S.length();
    map<char, int> M;
    for(auto c: S) M[c]++;

    if(M['L'] >= 2 && M['T'] >= 2 && M['I'] >= 2 && M['M'] >= 2) {
      if(N == 9 && M['E'] == 1) cout << "YES" << endl;
      else if(M['E'] >= 2) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
}
