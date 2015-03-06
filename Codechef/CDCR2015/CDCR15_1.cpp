// Jimmy is Late

#include <iostream>
#include <string>
using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    int N, K; cin >> N >> K;
    string s; cin >> s;
    bool flag = true;
    int curr_start = -1;

    for(int i = 0; i < N; i++){
      if(s[i] == '#' && curr_start == -1){
        curr_start = i;
      }
      else if(s[i] == '.' && curr_start != -1){
        if((i - curr_start + 2) > K) {
          flag = false;
          break;
        }
        curr_start = -1;
      }
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
