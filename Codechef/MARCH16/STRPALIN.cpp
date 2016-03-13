#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    string A, B; cin >> A >> B;
    map<char, bool> X, Y;
    for(char c: A) X[c] = true;
    for(char c: B) Y[c] = true;

    bool pos = false;
    for(char c = 'a'; c <= 'z'; c++) {
      if(X[c] && Y[c]) pos = true;
    }
    cout << (pos ? "Yes" : "No") << endl;
  }
}
