// Message Typing

#include <iostream>
#include <string>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    string s; cin >> s;
    int ans = 0;
    for(char c: s){
      ans += c - 'a' + 1;
    }
    cout << ans << endl;
  }
}
