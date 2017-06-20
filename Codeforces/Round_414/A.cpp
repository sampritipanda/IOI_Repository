#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int a, b, c; cin >> a >> b >> c;

  int N; cin >> N;
  int ans = 0;
  while(N--) {
    int x; cin >> x;
    if(x > b && x < c) ans++;
  }
  cout << ans << endl;
}
