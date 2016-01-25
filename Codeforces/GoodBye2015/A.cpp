#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int x; string a, b; cin >> x >> a >> b;

  if(b == "month") {
    int ans[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(x <= 29) cout << 12 << endl;
    else if(x == 30) cout << 11 << endl;
    else cout << 7 << endl;
  }
  else {
    int ans[] = {0, 52, 52, 52, 52, 53, 53, 52};
    cout << ans[x] << endl;
  }
}
