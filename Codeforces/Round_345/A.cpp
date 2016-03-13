#include <iostream>

using namespace std;

int main() {
  int A, B; cin >> A >> B;
  int ans = 0;

  while(A > 0 && B > 0) {
    if(A == 1 && B == 1) break;

    if(A <= B) {
      A += 1;
      B -= 2;
    }
    else {
      A -= 2;
      B += 1;
    }
    ans++;
  }

  cout << ans << endl;
}
