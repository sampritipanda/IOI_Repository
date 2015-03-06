// A and B and Chess

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
  int white = 0, black = 0;
  for(int i = 0; i < 8; i++){
    string s; cin >> s;
    for(int j = 0; j < 8; j++){
      char c = toupper(s[j]);
      int curr = 0;
      if(c == 'Q') curr = 9;
      else if(c == 'R') curr = 5;
      else if(c == 'B') curr = 3;
      else if(c == 'N') curr = 3;
      else if(c == 'P') curr = 1;

      if(int(s[j]) >= 97) black += curr;
      else white += curr;
    }
  }

  if(white > black) cout << "White" << endl;
  else if(white == black) cout << "Draw" << endl;
  else cout << "Black" << endl;
}
