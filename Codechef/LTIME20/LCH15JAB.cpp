// Piece of cake

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    string s; cin >> s;
    map<char, int> chars;
    int N = s.length();
    for(int i = 0; i < N; i++) {
      chars[s[i]]++;
    }

    bool flag = false;
    for(auto it: chars){
      if(it.second == N - it.second){
        cout << "YES" << endl;
        flag = true;
        break;
      }
    }
    if(!flag) cout << "NO" << endl;
  }
}
