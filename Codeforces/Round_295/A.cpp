#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main () {
  int N; cin >> N;
  string s; cin >> s;

  char count[26];
  for(int i = 0; i < 26; i++) count[i] = 0;

  for(auto c: s) count[toupper(c) - 'A']++;

  bool flag = true;
  for(int i = 0; i < 26; i++){
    if(count[i] == 0) {
      flag = false;
      break;
    }
  }

  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
}
