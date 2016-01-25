#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int x1, y1; cin >> x1 >> y1;
  int x2, y2; cin >> x2 >> y2;
  int x3, y3; cin >> x3 >> y3;

  if(x1 == x2 && x2 == x3 || y1 == y2 && y2 == y3) cout << 1 << endl;
  else if(x1 == x2) {
    if(y3 > min(y1, y2) && y3 < max(y1, y2)) cout << 3 << endl;
    else cout << 2 << endl;
  }
  else if(x1 == x3) {
    if(y2 > min(y1, y3) && y2 < max(y1, y3)) cout << 3 << endl;
    else cout << 2 << endl;
  }
  else if(x2 == x3) {
    if(y1 > min(y2, y3) && y1 < max(y2, y3)) cout << 3 << endl;
    else cout << 2 << endl;
  }
  else if(y1 == y2) {
    if(x3 > min(x1, x2) && x3 < max(x1, x2)) cout << 3 << endl;
    else cout << 2 << endl;
  }
  else if(y1 == y3) {
    if(x2 > min(x1, x3) && x2 < max(x1, x3)) cout << 3 << endl;
    else cout << 2 << endl;
  }
  else if(y2 == y3) {
    if(x1 > min(x2, x3) && x1 < max(x2, x3)) cout << 3 << endl;
    else cout << 2 << endl;
  }
  else cout << 3 << endl;
}
