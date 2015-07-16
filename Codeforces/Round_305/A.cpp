#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
  if(b == 0) return a;
  else return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
  return (a * b)/gcd(a, b);
}

int main() {
  int m; cin >> m;
  long long h1, a1; cin >> h1 >> a1;
  long long x1, y1; cin >> x1 >> y1;
  long long h2, a2; cin >> h2 >> a2;
  long long x2, y2; cin >> x2 >> y2;

  long long a_time = -1, b_time = -1;
  long long ans = -1;
  int i;
  for(i = 0; i < 38000000; i++) {
    if(a_time == -1 && h1 == a1) a_time = i;
    if(a_time == -1 && h2 == a2) b_time = i;
    if(h1 == a1 && h2 == a2) {
      ans = i;
      break;
    }

    h1 = (x1 * h1 + y1) % m;
    h2 = (x2 * h2 + y2) % m;
  }

  if(ans != -1) cout << ans << endl;
  else if(a_time != -1 && b_time != -1) {
    cout << lcm(a_time, b_time) << endl;
  }
  else cout << -1 << endl;
}
