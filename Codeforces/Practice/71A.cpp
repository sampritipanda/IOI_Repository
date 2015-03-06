// Way Too Long Words

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
  int n; cin >> n;

  while(n--){
    string s; cin >> s;
    if(s.length() <= 10) cout << s << endl;
    else {
      string n;
      n = s[0];
      ostringstream oss;
      oss << s.length() - 2;
      n += oss.str();
      n += s[s.length() - 1];
      cout << n << endl;
    }
  }
}
