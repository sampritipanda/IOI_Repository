#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  bool A, B, C, D; cin >> A >> B >> C >> D;

  bool M = A | B;
  bool N = C ^ D;
  bool O = B & C;
  bool P = A | D;

  bool X = M & N;
  bool Y = O ^ P;

  bool ans = !(X | Y);

  cout << ans << endl;
}
