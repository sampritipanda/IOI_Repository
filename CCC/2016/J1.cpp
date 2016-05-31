#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int cnt = 0;
  for(int i = 1; i <= 6; i++) {
    char c; cin >> c;
    if(c == 'W') cnt++;
  }

  if(cnt == 5 || cnt == 6) cout << 1 << endl;
  else if(cnt == 3 || cnt == 4) cout << 2 << endl;
  else if(cnt == 1 || cnt == 2) cout << 3 << endl;
  else cout << -1 << endl;
}
