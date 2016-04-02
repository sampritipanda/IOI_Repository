#include <iostream>

using namespace std;

int main() {
  long long x; cin >> x;

  if(x == 0) cout << 0 << endl;
  else cout << (1LL << x) << endl;
}
