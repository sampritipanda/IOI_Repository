#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int F[1001];

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    for(int i = 1; i <= 1000; i++) F[i] = 0;
    for(int i = 1; i <= N; i++) {
      int x; cin >> x;
      F[x]++;
    }

    int ans = -1;
    for(int i = 1; i <= 1000; i++) {
      if(F[i] >= 4) ans = max(ans, i * i);
      for(int j = i + 1; j <= 1000; j++) {
        if(F[i] >= 2 && F[j] >= 2) {
          ans = max(ans, i * j);
        }
      }
    }

    cout << ans << endl;
  }
}
