#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long k, n, w; cin >> k >> n >> w;
  long long ans = (w * (2*k + (w - 1) * k))/2;
  ans = max(ans - n, 0LL);
  cout << ans << endl;
}
