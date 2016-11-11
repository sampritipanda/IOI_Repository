#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    if(x1 == x2) {
      if(y1 > y2) cout << "down";
      else cout << "up";
    }
    else if(y1 == y2) {
      if(x1 < x2) cout << "right";
      else cout << "left";
    }
    else cout << "sad";
    cout << endl;
  }
}
