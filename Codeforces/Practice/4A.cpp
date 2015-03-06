// Watermelon

#include <iostream>

using namespace std;

int main() {
  int w; cin >> w;
  bool flag = true;
  if(w % 2 == 1) flag = false;
  else if(w/2 <= 1) flag = false;

  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
}
