// Chef and the XORed Number

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  // for(int t = 1; t <= 10000; t++) {
  //   for(int i = 1; i <= (1 << 25); i++) {
  //     if((i ^ (i + 1)) == t) {
  //       cout << t << " " << i << endl;
  //       break;
  //     }
  //   }
  // }
  //
  // return 0;
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    int num = N + 1;
    if(!(num & (num - 1))) {
      if(N == 1) cout << 2 << endl;
      else cout << N/2 << endl;
    }
    else {
      cout << -1 << endl;
    }
  }
}
