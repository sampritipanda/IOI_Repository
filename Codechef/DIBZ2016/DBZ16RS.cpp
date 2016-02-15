#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    long long a = 0, b = 0;
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
      int x; cin >> x;
      if(x & 1) b++;
      else a++;
    }

    cout << a * b + ((a - 1) * a)/2 << endl;
  }
}
