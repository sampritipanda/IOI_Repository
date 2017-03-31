#include <iostream>
#include <climits>

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  cout << 100000 << " " << -1 << endl;
  for(int i = 1; i <= 100000; i++) {
    cout << 1000000000;
    if(i < 100000) cout << " ";
  }
  cout << endl;
}
