#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  // i l o v e y u
  map<char, int> M;
  string S; cin >> S;
  for(char c: S) M[c]++;

  if(M['i'] >= 1 && M['l'] >= 1 && M['o'] >= 2 && M['v'] >= 1 && M['e'] >= 1 && M['y'] >= 1 && M['u'] >= 1) {
    cout << "happy" << endl;
  }
  else {
    cout << "sad" << endl;
  }
}
