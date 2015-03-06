// Chewbaсca and Number

#include <iostream>
#include <string>

using namespace std;

int main() {
  string s; cin >> s;
  int N = s.length();

  for(int i = 0; i < N; i++){
    if((s[i] - '0') >= 5) s[i] = (9 - (s[i] - '0')) + '0';
  }

  if(s[0] == '0') s[0] = '9';
  cout << s << endl;
}
