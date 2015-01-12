// Dhapu and Hamming Distance

#include <iostream>
#include <string>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    string a, b; cin >> a >> b;
    if(a.length() != b.length()) cout << -1 << endl;
    else {
      int count = 0;
      for(int i = 0; i < a.length(); i++){
        if(a[i] != b[i]) count++;
      }
      cout << count << endl;
    }
  }
}
