// Mr. Kitayuta's Gift (Div. 2 version)

#include <iostream>
#include <string>

using namespace std;

bool is_palin(string input){
  return (input == string(input.rbegin(), input.rend()));
}

int main() {
  string s; cin >> s;
  int N = s.length();

  if(is_palin(s)){
    if(N % 2 == 0) s.insert(N/2, 1, 'a');
    else s.insert(N/2, 1, s[N/2]);

    cout << s << endl;
  }
  else {
    bool flag = false;
    for(int i = 0; i < N; i++){ // revive
      for(int j = 0; j < N; j++){
        string temp = s;
        temp.insert(i, 1, s[j]);
        if(is_palin(temp)){
          s = temp;
          flag = true;
          break;
        }
      }
      if(flag) break;
    }
    if(!flag){
      string temp = s;
      temp += s[0];
      if(is_palin(temp)) {
        flag = true;
        s = temp;
      }
    }
    if(!flag) cout << "NA" << endl;
    else cout << s << endl;
  }
}
