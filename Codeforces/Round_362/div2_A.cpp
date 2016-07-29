#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long T, S, X; cin >> T >> S >> X;
  X -= T;

  if((X < S && X == 0) || (X >= S && X % S <= 1)) cout << "YES" << endl;
  else cout << "NO" << endl;
}
