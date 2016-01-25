#include <iostream>

using namespace std;

int main() {
  int cnt[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

  int L, R; cin >> L >> R;
  long long ans = 0;
  for(int i = L; i <= R; i++) {
    int t = i;
    while(t > 0) {
      ans += cnt[t % 10];
      t /= 10;
    }
  }
  cout << ans << endl;
}
