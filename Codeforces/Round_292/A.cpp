// Drazil and Date

#include <iostream>
#include <cmath>

using namespace std;

int main () {
  int a, b, s; cin >> a >> b >> s;

  int min_step = abs(a - 0) + abs(b - 0);
  if(s < min_step) cout << "No" << endl;
  else if((s - min_step) % 2 == 1) cout << "No" << endl;
  else cout << "Yes" << endl;
}
