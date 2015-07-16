// Tickets

#include <iostream>
#include <string>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    string S; cin >> S;

    bool flag = true;
    char a = S[0], b = S[1];
    if(a == b) flag = false;
    for(int i = 2; i < S.length(); i++){
      if(i % 2 == 0){
        if(S[i] != a) {
          flag = false;
          break;
        }
      }
      else {
        if(S[i] != b) {
          flag = false;
          break;
        }
      }
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
