// Sheldon and the mission

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

int N, x, y;

bool sort_compare(pair<int, int> a, pair<int, int> b){
    int d_a = (a.first - x)*(a.first - x) + (a.second - y)*(a.second - y);
    int d_b = (b.first - x)*(b.first - x) + (b.second - y)*(b.second - y);

    if(d_a <= d_b) return true;
    else return false;
}

int main() {
  cin >> N >> x >> y;
  set<pair<int, int> > points_set;
  vector<pair<int, int> > points;
  for(int i = 0; i < N; i++) {
      int a, b; cin >> a >> b;
      points_set.insert({a, b});
  }
  points_set.insert({x, y});
  for(auto it: points_set) points.push_back({it.first, it.second});

  sort(points.begin(), points.end(), sort_compare);
  int K = points.size();
  long long dp[K];
  dp[0] = 0;
  for(int i = 1; i < K; i++){
      dp[i] = LLONG_MAX;
      for(int j = 0; j < i; j++){
          int a_x = points[i].first, a_y = points[i].second;
          int b_x = points[j].first, b_y = points[j].second;

          dp[i] = min(dp[i], dp[j] + ((a_x - b_x)*(a_x - b_x) + (a_y - b_y)*(a_y - b_y)));
      }
  }

  long long ans = LLONG_MAX;
  for(int i = 0; i < K; i++){
      ans = min(ans, dp[i] + (points[i].first * points[i].first + points[i].second * points[i].second));
  }

  cout << ans << endl;
}

