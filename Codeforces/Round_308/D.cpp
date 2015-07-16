// Vanya and Triangles

#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
set<pair<int, int> > points_set;
vector<pair<int, int> > points;

int main() {
  int N; cin >> N;

  for(int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    points_set.insert({x, y});
  }
  for(auto it: points_set) {
    points.push_back({it.first, it.second});
  }
  N = points.size();

  long long total = N; total *= (total - 1) * (total - 2);
  total /= 6;

  map<double, int> slopes;
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      if(points[j].first == points[i].first) {
        slopes[10000000.0]++;
      }
      else {
        double curr_slope = (points[j].second - points[i].second)/(points[j].first - points[i].first);
        curr_slope = round(curr_slope * 100000.0)/100000.0;
        slopes[curr_slope]++;
      }
    }
  }

  for(auto it: slopes) {
    total -= (it.second * (it.second - 1) * (it.second - 2))/6;
  }

  cout << total << endl;
}

