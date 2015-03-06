// Sheldon and the mission

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int N, x, y; cin >> N >> x >> y;
  vector<pair<int, int> > points(N);
  for(int i = 0; i < N; i++) cin >> points[i].first >> points[i].second;

  queue<pair<pair<int, int>, int> > Q;
  int ans = -1;
  Q.push({{0, 0}, 0});

  while(!Q.empty()){
    auto curr = Q.front();
    int c_x = curr.first.first, c_y = curr.first.second;
    Q.pop();

    if(c_x == x && c_y == y) {
      ans = curr.second;
      break;
    }

    int direct = (x - c_x)*(x - c_x) + (y - c_y)*(y - c_y);
    int nearest_dist = direct;
    int n_x = x, n_y = y;
    for(int i = 0; i < N; i++){
      int d = (c_x - points[i].first)*(c_x - points[i].first) + (c_y - points[i].second)*(c_y - points[i].second);
      int temp_d = d;
      d += (x - points[i].first)*(x - points[i].first) + (y - points[i].second)*(y - points[i].second);

      if(d < direct && temp_d < nearest_dist){
        nearest_dist = temp_d;
        n_x = points[i].first;
        n_y = points[i].second;
      }
    }

    cout << n_x << " " << n_y << " " << nearest_dist << endl;
    Q.push({{n_x, n_y}, curr.second + nearest_dist});
  }

  cout << ans << endl;
}
