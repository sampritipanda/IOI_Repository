#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    int cnt = 0, cnt_0 = 0, cnt_1 = 0, cnt_minus1 = 0;
    while(N--) {
      int x; cin >> x;

      if(abs(x) >= 2) cnt++;
      else if(x == -1) cnt_minus1++;
      else if(x == 0) cnt_0++;
      else cnt_1++;
    }

    if(cnt >= 2) cout << "no";
    else if(cnt == 1 && cnt_minus1 > 0) cout << "no";
    else if(cnt_minus1 >= 2 && cnt_1 == 0) cout << "no";
    else cout << "yes";

    cout << endl;
  }
}
