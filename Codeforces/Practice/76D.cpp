#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  unsigned long long A, B; cin >> A >> B;

  if(A < B) cout << -1 << endl;
  else if((A & 1ULL) != (B & 1ULL)) cout << -1 << endl;
  else {
    unsigned long long X = (A - B) >> 1ULL;
    unsigned long long Y = X + B;
    cout << X << " " << Y << endl;
  }
}
