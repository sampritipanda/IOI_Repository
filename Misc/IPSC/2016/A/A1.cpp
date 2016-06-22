#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    string ans = "";
    for(int i = 0; i < 10; i++) {
      string S; cin >> S;
      ans += S;
    }
    ans += 'A';
    ans += 'A';

    assert(ans.length() == 42);
    cout << ans << endl;
  }
}
