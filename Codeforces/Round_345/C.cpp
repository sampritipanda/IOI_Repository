#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<long long, long long> x_cnt, y_cnt;
map<pair<long long, long long>, long long> pair_cnt;

int main() {
  ios::sync_with_stdio(false);

  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    x_cnt[x]++;
    y_cnt[y]++;
    pair_cnt[make_pair(x, y)]++;
  }

  long long ans = 0;

  for(auto it: x_cnt) {
    ans += (it.second * (it.second - 1))/2;
  }
  for(auto it: y_cnt) {
    ans += (it.second * (it.second - 1))/2;
  }
  for(auto it: pair_cnt) {
    ans -= (it.second * (it.second - 1))/2;
  }

  cout << ans << endl;
}
