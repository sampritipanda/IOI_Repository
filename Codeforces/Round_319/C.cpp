// Points on Plane

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int, int>, int> > points1, points2;

int main() {
  ios::sync_with_stdio(false);

  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    points1.push_back({{x, y}, i + 1});
    points2.push_back({{y, x}, i + 1});
  }

  sort(points1.begin(), points1.end());
  sort(points2.begin(), points2.end());

  long long ans1 = 0, ans2 = 0;
  for(int i = 0; i < N - 1; i++) {
    ans1 += abs(points1[i].first.first - points1[i + 1].first.first) + abs(points1[i].first.second - points1[i + 1].first.second);
  }
  for(int i = 0; i < N - 1; i++) {
    ans2 += abs(points2[i].first.first - points2[i + 1].first.first) + abs(points2[i].first.second - points2[i + 1].first.second);
  }

  if(ans1 < ans2) {
    for(auto it: points1) cout << it.second << " ";
    cout << endl;
  }
  else {
    for(auto it: points2) cout << it.second << " ";
    cout << endl;
  }
}
