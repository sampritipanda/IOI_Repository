#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    string S; cin >> S;
    int a = 0, b = 0;
    for(auto c: S) {
      if(c == 'a') a++;
      else b++;
    }
    cout << min(a, b) << endl;
  }
}
