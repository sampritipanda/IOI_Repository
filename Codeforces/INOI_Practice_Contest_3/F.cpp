#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int N; cin >> N;
  int min_p = 111111111;
  int ans = 0;
  for(int i = 0; i < N; i++) {
    int x, a; cin >> a >> x;
    min_p = min(min_p, x);
    ans += min_p * a;
  }
  cout << ans << endl;
}
