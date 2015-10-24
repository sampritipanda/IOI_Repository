#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a, b; cin >> a >> b;
  int x = min(a, b);
  a -= x; b -= x;
  int y = a/2 + b/2;
  cout << x << " " << y << endl;
}
