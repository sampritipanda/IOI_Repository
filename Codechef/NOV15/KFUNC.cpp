#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    long long A, D, L, R; cin >> A >> D >> L >> R;
    vector<long long> arr;
    for(int i = 0; i < 9; i++) {
      arr.push_back((A + i*D) % 9);
      if(arr[i] == 0) arr[i] = 9;
    }
    for(int i = 1; i < 9; i++) {
      arr[i] = arr[i - 1] + arr[i];
    }

    long long ans = 0;
    ans += R/9 * arr[8];
    if(R % 9 > 0) ans += arr[R % 9 - 1];
    if(L > 1) {
      L--;
      ans -= L/9 * arr[8];
      if(L % 9 > 0) ans -= arr[L % 9 - 1];
    }

    cout << ans << endl;
  }
}
