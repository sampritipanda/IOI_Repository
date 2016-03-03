#include <iostream>

using namespace std;

int main() {
  int A, B, C; cin >> A >> B >> C;

  C -= A;
  int cnt = C/B;

  if(cnt % 2 == 0) cout << "Lucky Chef" << endl;
  else cout << "Unlucky Chef" << endl;
}
