#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string X, Y; cin >> X >> Y;

  string A = "", B = "";
  bool start = false;
  for(auto c: X) {
    if(c == '0' && !start) {
      continue;
    }
    else {
      A += c;
      start = true;
    }
  }
  start = false;
  for(auto c: Y) {
    if(c == '0' && !start) {
      continue;
    }
    else {
      B += c;
      start = true;
    }
  }

  if(A == B) cout << '=' << endl;
  else if(A.size() < B.size()) cout << '<' << endl;
  else if(A.size() > B.size()) cout << '>' << endl;
  else cout << (A < B ? '<' : '>') << endl;
}
