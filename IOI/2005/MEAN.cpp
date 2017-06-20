#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  int ans = INT_MAX;
  int x; cin >> x; N--;
  while(N--) {
    int c; cin >> c;
    ans = min(ans, c - x + 1);
    x = c;
  }
  cout << ans << endl;
}
