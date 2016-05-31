#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;

  int ans = 0;
  while(N--) {
    int x; cin >> x;
    ans += x;
  }

  cout << (ans + 1)/2 << endl;
}
