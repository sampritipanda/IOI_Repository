#include <iostream>

using namespace std;

int main() {
  int a, b, c; cin >> a >> b >> c;
  int x, y, z; cin >> x >> y >> z;

  int sum = 0, sum2 = 0;
  if(a < x) sum += x - a;
  else sum2 += (a - x)/2;

  if(b < y) sum += y - b;
  else sum2 += (b - y)/2;

  if(c < z) sum += z - c;
  else sum2 += (c - z)/2;

  if(sum > sum2) cout << "No" << endl;
  else cout << "Yes" << endl;
}
