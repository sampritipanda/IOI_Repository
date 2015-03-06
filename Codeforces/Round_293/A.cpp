// Vitaly and Strings

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s; cin >> s;
  string t; cin >> t;

  int i = s.length() - 1;
  while(i >= 0){
    if(s[i] == 'z'){
      s[i] = 'a';
      i--;
    }
    else {
      s[i]++;
      break;
    }
  }
  if(lexicographical_compare(s.begin(), s.end(), t.begin(), t.end())) cout << s << endl;
  else cout << "No such string" << endl;
}
