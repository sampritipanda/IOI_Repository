#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, D, H; cin >> N >> D >> H;

  if(D == H) {
    if(H == 1) {
      if(N == 2) cout << 1 << " " << 2 << endl;
      else cout << -1 << endl;
    }
    else {
      int used = 1;
      for(int i = 2; i <= H + 1; i++, used++) cout << (i - 1) << " " << i << endl;
      for(int i = used + 1; i <= N; i++) {
        cout << 2 << " " << i << endl;
      }
    }
  }
  else if(D - H <= H) {
    int used = 1;
    for(int i = 2; i <= H + 1; i++) {
      cout << (i - 1) << " " << i << endl;
      used++;
    }
    cout << 1 << " " << ++used << endl;
    for(int i = 2; i <= D - H; i++) {
      cout << used << " " << used + 1 << endl;
      used++;
    }

    for(int i = used + 1; i <= N; i++) cout << 1 << " " << i << endl;
  }
  else {
    cout << -1 << endl;
  }
}
