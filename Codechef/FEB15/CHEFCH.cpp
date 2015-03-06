// Chef and Chain 

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    string s; cin >> s;
    int N = s.length();
    int count_a = 0, count_b = 0;
    for(int i = 0; i < N; i++){
      if(i % 2 == 0){
        if(s[i] == '+') count_a++;
      }
      else {
        if(s[i] == '-') count_a++;
      }
    }
    for(int i = 0; i < N; i++){
      if(i % 2 == 0){
        if(s[i] == '-') count_b++;
      }
      else {
        if(s[i] == '+') count_b++;
      }
    }

    cout << min(count_a, count_b) << endl;
  }
}
