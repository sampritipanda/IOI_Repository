// Lucky Four

#include <iostream>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    string num; cin >> num;
    int count = 0;
    for(auto c: num){
      if(c == '4') count++;
    }
    cout << count << endl;
  }
}
