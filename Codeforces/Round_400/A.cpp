#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  string A, B; cin >> A >> B;
  cout << A << " " << B << endl;

  int N; cin >> N;

  while(N--) {
    string X, Y; cin >> X >> Y;
    if(X == A) A = Y;
    else B = Y;
    cout << A << " " << B << endl;
  }
}
