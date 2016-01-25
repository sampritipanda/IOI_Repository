// Boomerang Constellations

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    int N; cin >> N;
    vector<pair<long long, long long> > points;

    for(int i = 0; i < N; i++) {
      long long x, y; cin >> x >> y;
      points.push_back({x, y});
    }

    long long ans = 0;
    for(int i = 0; i < N; i++) {
      map<long long, long long> cnt;
      for(int j = 0; j < N; j++) {
        if(i == j) continue;

        long long dist = (points[j].first - points[i].first) * (points[j].first - points[i].first) + (points[j].second - points[i].second) * (points[j].second - points[i].second);
        cnt[dist]++;
      }

      for(auto it: cnt) {
        if(it.second >= 2) {
          ans += (it.second * (it.second - 1))/2;
        }
      }
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
}
