#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long x, y; cin >> x >> y;
  long long a, b; cin >> a >> b;

  long long ans = min(abs(x - a), abs(y - b));

  if(x < a) x += ans;
  else x -= ans;

  if(y < b) y += ans;
  else y -= ans;

  ans += abs(x - a) + abs(y - b);
  cout << ans << endl;
}
