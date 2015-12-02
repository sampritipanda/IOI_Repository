
#include <iostream>
using namespace std;

int main() {
  long long K, L, R; cin >> K >> L >> R;
  long long ans = 0;
  if(L >= 0 && R >= 0) {
    ans += R/K;
    if(L == 0) ans += 1;
    else ans -= (L - 1)/K;
  }
  else if(R >= 0 && L < 0) {
    ans += R/K + 1;
    ans += -L/K;
  }
  else if(R < 0 && L < 0) {
    ans += -L/K - (-R - 1)/K;
  }

  cout << ans << endl;
}
