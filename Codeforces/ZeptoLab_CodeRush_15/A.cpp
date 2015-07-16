// King of Thieves

#include <iostream>

using namespace std;

int main() {
  int N; cin >> N;
  string s; cin >> s;

  bool flag = false;
  for(int i = 0; i < N; i++){
    for(int l = 1; l <= N; l++){
      int count = 0;
      for(int j = i; j < N; j += l){
        if(s[j] == '.') break;
        else count++;
      }
      if(count >= 5) {
        flag = true;
        break;
      }
    }
    if(flag) break;
  }

  if(flag) cout << "yes" << endl;
  else cout << "no" << endl;
}
