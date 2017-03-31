#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int ans[2][2] = { {1, 2}, {3, 4} };

  int N; cin >> N;

  cout << "YES" << endl;
  for(int i = 1; i <= N; i++) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    cout << ans[abs(x1) % 2][abs(y1) % 2] << endl;
  }
}
