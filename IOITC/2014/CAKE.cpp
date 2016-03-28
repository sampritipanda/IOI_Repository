#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>

using namespace std;

multiset<pair<double, int> > Q;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;
  while(N--) {
    int x; cin >> x;
    Q.insert({x, -1});
  }

  double ans = Q.rbegin()->first - Q.begin()->first;

  while(M--) {
    pair<double, int> curr = *Q.rbegin(); Q.erase(Q.find(curr));
    curr.second *= -1;
    curr.first = (curr.first * curr.second)/(curr.second + 1);
    curr.second++;
    curr.second *= -1;
    Q.insert(curr);

    ans = min(ans, Q.rbegin()->first - Q.begin()->first);
  }

  cout << fixed << setprecision(8) << ans << endl;
}
