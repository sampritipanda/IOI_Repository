// Contest

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  double a, b, c, d; cin >> a >> b >> c >> d;

  double misha = max(3*a/10, a - (a/250 * c));
  double vasya = max(3*b/10, b - (b/250 * d));

  if(misha > vasya) cout << "Misha" << endl;
  else if(misha < vasya) cout << "Vasya" << endl;
  else cout << "Tie" << endl;
}
