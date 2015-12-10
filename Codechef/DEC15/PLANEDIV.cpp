#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;

map<double, set<double> > cnt;

int main() {
  ios::sync_with_stdio(false);

  int T; cin >> T;

  while(T--) {
    cnt.clear();

    int N; cin >> N;
    while(N--) {
      int A, B; double C; cin >> A >> B >> C;
      int g = __gcd(A, B);
      A /= g; B /= g;

      cnt[-double(A)/double(B)].insert(C/g);
    }

    int ans = 0;
    for(auto it: cnt) ans = max(ans, (int)it.second.size());
    cout << ans << endl;
  }
}
