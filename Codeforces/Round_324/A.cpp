#include <iostream>

using namespace std;

int main() {
  int n, t; cin >> n >> t;

  if(t >= 2 && t <= 9) {
    for(int i = 1; i <= n; i++) cout << t;
    cout << endl;
  }
  else if(t == 10) {
    if(n == 1) cout << -1 << endl;
    else {
      cout << 1;
      for(int i = 2; i <= n; i++) cout << 0;
      cout << endl;
    }
  }
}
