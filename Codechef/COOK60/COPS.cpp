// Cops and the Thief Devu

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int M, x, y; cin >> M >> x >> y;
    bool safe[101]; for(int i = 1; i <= 100; i++) safe[i] = true;

    while(M--) {
      int a; cin >> a;
      int start = max(1, a - x * y);
      int end = min(100, a + x * y);
      for(int i = start; i <= end; i++) safe[i] = false;
    }

    int cnt = 0;
    for(int i = 1; i <= 100; i++) {
      if(safe[i]) cnt++;
    }

    cout << cnt << endl;
  }
}
