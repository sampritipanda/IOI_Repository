// String Task

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
  string s; cin >> s;
  string n = "";

  for(auto a: s){
    char c = toupper(a);
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y'){
    }
    else {
      n += '.';
      n += tolower(c);
    }
  }

  cout << n << endl;
}
